#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QTimer>
#include <QDateTime>
#include <qwaitcondition.h>
#include "stdio.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->port = new QextSerialPort("COM5");
    port->setBaudRate(BAUD38400);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
    port->setTimeout(100);

    //SyncTime();

    internalTimer = new QTimer( this ); // create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(getdata()) );
    internalTimer->start( 1000 );               // emit signal every second


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
    char acCmd[] = "G1";
    char acBuffer[64];
    QString format;

    int iEarthTemp;
    int iWindTemp;
    int iFireRaw;
    int iWaterRaw;
    int iEarthDuty;
    int iWindDuty;
    char acTime[32];


    if(port->open(QIODevice::ReadWrite) == true)
    {
       qDebug("Port opened!!");
       port->write(acCmd,sizeof(acCmd));

       sleepMs(100);
       if(port->bytesAvailable() > 2)
       {
            port->peek(acHeader,sizeof(acHeader));
            qDebug("Header: %s",acHeader);
       }

        if(acHeader[0] == 'G' && acHeader[1] == 'S')
        {
            port->read(acBuffer, port->bytesAvailable());
            QString Data = acBuffer;
            ui->rawdataEdit->clear();
            ui->rawdataEdit->insert(Data);

            sscanf(acBuffer, "GS%04d%04d%04d%04d%03d%03d%sDONE",&iEarthTemp, &iWindTemp, &iFireRaw, &iWaterRaw, &iEarthDuty,&iWindDuty, acTime);

            ui->EarthTemplineEdit->clear();
            ui->EarthTemplineEdit->insert(format.sprintf("%.01f",(double)(iEarthTemp)/10));

            ui->WindTemplineEdit->clear();
            ui->WindTemplineEdit->insert(format.sprintf("%.01f",(double)(iWindTemp)/10));

            ui->FirelineEdit->clear();
            ui->FirelineEdit->insert(format.sprintf("%d",iFireRaw));

            ui->WaterlineEdit->clear();
            ui->WaterlineEdit->insert(format.sprintf("%d",iWaterRaw));

            ui->EarthDutylineEdit->clear();
            ui->EarthDutylineEdit->insert(format.sprintf("%d",iEarthDuty));

            ui->WindDutylineEdit->clear();
            ui->WindDutylineEdit->insert(format.sprintf("%d",iWindDuty));

            ui->UnixTimelineEdit->clear();
            format.sprintf("%s",acTime);
            format.chop(4);
            ui->UnixTimelineEdit->insert(format);

        }

        port->close();
    }
}
void MainWindow::sleepMs(int milliseconds)
{
    QWaitCondition sleep;
    QMutex dummy;

    dummy.lock();
    sleep.wait(&dummy, milliseconds);

}

void MainWindow::SyncTime()
{

    char acUnixTime[32];
    char acBuffer[64];
    unsigned int uiControllerTime;

    QDateTime CurrentTime =  QDateTime::currentDateTime();
    sprintf(acUnixTime,"G2%dS\n",CurrentTime.toTime_t());

    qDebug(acUnixTime);

    if(port->open(QIODevice::ReadWrite) == true)
    {
       qDebug("Port opened!!");
       port->write(acUnixTime,sizeof(acUnixTime));

       sleepMs(1000);
       port->write("G5",sizeof("G5"));
       sleepMs(300);

       if(port->bytesAvailable() > 6)
       {
           port->read(acBuffer, port->bytesAvailable());
           uiControllerTime = atoi(acBuffer);
           qDebug("%d",uiControllerTime);
           qDebug("%d",CurrentTime.toTime_t());


           if(abs(CurrentTime.toTime_t() - uiControllerTime) < 60)
           {
            ui->statusLabel->clear();
            ui->statusLabel->setText("Status : Time Synced");
           }
           else
           {
            ui->statusLabel->clear();
            ui->statusLabel->setText("Status : Time Out of synced");
           }
       }
     port->close();
    }
}
