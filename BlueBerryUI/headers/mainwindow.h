#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "qextserialport.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QextSerialPort *port;
    QTimer *internalTimer;

private slots:
    void on_Update_Constants_clicked();
    void getdata();

};

#endif // MAINWINDOW_H
