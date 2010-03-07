#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QTimer>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    internalTimer = new QTimer( this ); // create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(getdata()) );
    internalTimer->start( 500 );               // emit signal every 5 seconds

    this->port = new QextSerialPort("/dev/ttyUSB0");
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

void MainWindow::on_Update_Constants_clicked()
{
    QString Proportional[3];
    QString Integral[3];
    QString Derivative[3];
    QString DataString("P");
    QString buffer;
    QString Ack;
    QMessageBox msgBox;



    char acbuffer[32];
    int numBytes = 0;
    float fTemp = 0.00;


    internalTimer->stop();
    Proportional[0] = ui->Pp_1->text();
    Proportional[1] = ui->Pp_2->text();
    Proportional[2] = ui->Pp_3->text();

    fTemp = Proportional[0].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";


    fTemp = Proportional[1].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";

    fTemp = Proportional[2].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";

    Integral[0] = ui->Ip_1->text();
    Integral[1] = ui->Ip_2->text();
    Integral[2] = ui->Ip_3->text();


    fTemp = Integral[0].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";

    fTemp = Integral[1].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";

    fTemp = Integral[2].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";

    Derivative[0] = ui->Dp_1->text();
    Derivative[1] = ui->Dp_2->text();
    Derivative[2] = ui->Dp_3->text();


    fTemp = Derivative[0].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += ".";

    fTemp = Derivative[1].toFloat();
    buffer.setNum(int(fTemp*100));;
    DataString += buffer;
    DataString += ".";

    fTemp = Derivative[2].toFloat();
    buffer.setNum(int(fTemp*100));
    DataString += buffer;
    DataString += "DO";

    qDebug("%d",DataString.length());
    qDebug("%s",qPrintable(DataString));

    if(port->open(QIODevice::ReadWrite) == true)
    {

       port->flush();
       port->write(qPrintable(DataString),DataString.length());
       usleep(300000);
       numBytes = port->bytesAvailable();
       qDebug("Ack bytes %d",numBytes);
       if(numBytes > 0)
       {
            memset(acbuffer,0,sizeof(acbuffer));
            port->read(acbuffer, numBytes);
            Ack = acbuffer;
            qDebug("Ack: %s",qPrintable(Ack));

            if(Ack.contains("ack"))
            {
                msgBox.setText("Ack Received!!");
                msgBox.exec();
            }
        }
    }

    internalTimer->start();
}

void MainWindow::getdata()
{
    /*
     *    This function will be tied to a timer, that will poll the arduino for information every 500ms.
     *    It will send request packet then wait for a response, timeout is none is recieved.
     */
    char buff[1024];
    char send[]="GS";
    int numBytes;

    //qDebug("In getdata function");


    if(port->open(QIODevice::ReadWrite) == true)
    {
       port->write(send,sizeof(send));
       numBytes = port->bytesAvailable();

       if(numBytes >=15)
       {
        int i = port->read(buff, numBytes);
        if (i != -1)
            buff[i] = '\0';
        else
            buff[0] = '\0';

        QString msg = buff;
        ui->COMM_DATA->clear();
        ui->COMM_DATA->insert(msg);

        ui->MOS_PLANT1->clear();
        ui->MOS_PLANT1->insert(msg.mid(2,4));

        ui->MOS_PLANT2->clear();
        ui->MOS_PLANT2->insert(msg.mid(6,4));

        ui->MOS_PLANT3->clear();
        ui->MOS_PLANT3->insert(msg.mid(10,4));

        ui->PWM_PLANT1->clear();
        ui->PWM_PLANT1->insert(msg.mid(14,2));

        ui->PWM_PLANT2->clear();
        ui->PWM_PLANT2->insert(msg.mid(16,2));

        ui->PWM_PLANT3->clear();
        ui->PWM_PLANT3->insert(msg.mid(18,2));

       }
       else
           qDebug("%d byte received",numBytes);




    }
    else
    {
        qDebug("could not open port");
        //could not open port
    }



}

