#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QTimer>
#include <qwaitcondition.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    internalTimer = new QTimer( this ); // create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(getdata()) );
    internalTimer->start( 1000 );               // emit signal every second

    this->port = new QextSerialPort("COM3");
    port->setBaudRate(BAUD38400);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
    port->setTimeout(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::getdata()
{
    char acHeader[2];
    char acBuffer[64];
    QWaitCondition sleep;
    QMutex dummy;


    if(port->open(QIODevice::ReadWrite) == true)
    {

       port->write("G1",sizeof("G1"));
       qDebug("sent G1");

       while(port->peek(acHeader,sizeof(acHeader)) != sizeof(acHeader) && (port->bytesAvailable() > 1))
       {
            dummy.lock();
            sleep.wait(&dummy, 100);
       }

       qDebug("Header: %s ", acHeader);
        if(acHeader[0] == 'G' && acHeader[1] == 'S')
        {
            port->read(acBuffer, port->bytesAvailable());
            QString Data = acBuffer;
            ui->rawdataEdit->clear();
            ui->rawdataEdit->insert(Data);
        }


    }



}
