/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Feb 21 22:26:51 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLineEdit *Pp_1;
    QLabel *label_12;
    QLineEdit *Pp_2;
    QLabel *label_13;
    QLineEdit *Pp_3;
    QLabel *label_14;
    QLineEdit *Ip_1;
    QLineEdit *Ip_2;
    QLabel *label_16;
    QLineEdit *Ip_3;
    QLabel *label_17;
    QLineEdit *Dp_1;
    QLabel *label_18;
    QLineEdit *Dp_2;
    QLabel *label_19;
    QLineEdit *Dp_3;
    QLabel *label_15;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *MOS_PLANT1;
    QLabel *label_7;
    QLineEdit *MOS_PLANT2;
    QLabel *label_10;
    QLineEdit *MOS_PLANT3;
    QLabel *label_2;
    QLineEdit *PWM_PLANT1;
    QLabel *label_6;
    QLineEdit *PWM_PLANT2;
    QLabel *label_9;
    QLineEdit *PWM_PLANT3;
    QLabel *label_3;
    QLineEdit *WATER_PLANT1;
    QLabel *label_5;
    QLineEdit *WATER_PLANT2;
    QLabel *label_8;
    QLineEdit *WATER_PLANT3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *COMM_DATA;
    QPushButton *Update_Constants;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(973, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 250, 812, 92));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        Pp_1 = new QLineEdit(layoutWidget);
        Pp_1->setObjectName(QString::fromUtf8("Pp_1"));

        gridLayout_2->addWidget(Pp_1, 0, 1, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 2, 1, 1);

        Pp_2 = new QLineEdit(layoutWidget);
        Pp_2->setObjectName(QString::fromUtf8("Pp_2"));

        gridLayout_2->addWidget(Pp_2, 0, 3, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 4, 1, 1);

        Pp_3 = new QLineEdit(layoutWidget);
        Pp_3->setObjectName(QString::fromUtf8("Pp_3"));

        gridLayout_2->addWidget(Pp_3, 0, 5, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 1, 0, 1, 1);

        Ip_1 = new QLineEdit(layoutWidget);
        Ip_1->setObjectName(QString::fromUtf8("Ip_1"));

        gridLayout_2->addWidget(Ip_1, 1, 1, 1, 1);

        Ip_2 = new QLineEdit(layoutWidget);
        Ip_2->setObjectName(QString::fromUtf8("Ip_2"));

        gridLayout_2->addWidget(Ip_2, 1, 3, 1, 1);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 1, 4, 1, 1);

        Ip_3 = new QLineEdit(layoutWidget);
        Ip_3->setObjectName(QString::fromUtf8("Ip_3"));

        gridLayout_2->addWidget(Ip_3, 1, 5, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 2, 0, 1, 1);

        Dp_1 = new QLineEdit(layoutWidget);
        Dp_1->setObjectName(QString::fromUtf8("Dp_1"));

        gridLayout_2->addWidget(Dp_1, 2, 1, 1, 1);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_2->addWidget(label_18, 2, 2, 1, 1);

        Dp_2 = new QLineEdit(layoutWidget);
        Dp_2->setObjectName(QString::fromUtf8("Dp_2"));

        gridLayout_2->addWidget(Dp_2, 2, 3, 1, 1);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_2->addWidget(label_19, 2, 4, 1, 1);

        Dp_3 = new QLineEdit(layoutWidget);
        Dp_3->setObjectName(QString::fromUtf8("Dp_3"));

        gridLayout_2->addWidget(Dp_3, 2, 5, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 1, 2, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 30, 812, 92));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        MOS_PLANT1 = new QLineEdit(layoutWidget1);
        MOS_PLANT1->setObjectName(QString::fromUtf8("MOS_PLANT1"));

        gridLayout->addWidget(MOS_PLANT1, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        MOS_PLANT2 = new QLineEdit(layoutWidget1);
        MOS_PLANT2->setObjectName(QString::fromUtf8("MOS_PLANT2"));

        gridLayout->addWidget(MOS_PLANT2, 0, 3, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 4, 1, 1);

        MOS_PLANT3 = new QLineEdit(layoutWidget1);
        MOS_PLANT3->setObjectName(QString::fromUtf8("MOS_PLANT3"));

        gridLayout->addWidget(MOS_PLANT3, 0, 5, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        PWM_PLANT1 = new QLineEdit(layoutWidget1);
        PWM_PLANT1->setObjectName(QString::fromUtf8("PWM_PLANT1"));

        gridLayout->addWidget(PWM_PLANT1, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        PWM_PLANT2 = new QLineEdit(layoutWidget1);
        PWM_PLANT2->setObjectName(QString::fromUtf8("PWM_PLANT2"));

        gridLayout->addWidget(PWM_PLANT2, 1, 3, 1, 1);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 4, 1, 1);

        PWM_PLANT3 = new QLineEdit(layoutWidget1);
        PWM_PLANT3->setObjectName(QString::fromUtf8("PWM_PLANT3"));

        gridLayout->addWidget(PWM_PLANT3, 1, 5, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        WATER_PLANT1 = new QLineEdit(layoutWidget1);
        WATER_PLANT1->setObjectName(QString::fromUtf8("WATER_PLANT1"));

        gridLayout->addWidget(WATER_PLANT1, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        WATER_PLANT2 = new QLineEdit(layoutWidget1);
        WATER_PLANT2->setObjectName(QString::fromUtf8("WATER_PLANT2"));

        gridLayout->addWidget(WATER_PLANT2, 2, 3, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 4, 1, 1);

        WATER_PLANT3 = new QLineEdit(layoutWidget1);
        WATER_PLANT3->setObjectName(QString::fromUtf8("WATER_PLANT3"));

        gridLayout->addWidget(WATER_PLANT3, 2, 5, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(110, 170, 521, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        COMM_DATA = new QLineEdit(layoutWidget2);
        COMM_DATA->setObjectName(QString::fromUtf8("COMM_DATA"));

        horizontalLayout->addWidget(COMM_DATA);

        Update_Constants = new QPushButton(centralwidget);
        Update_Constants->setObjectName(QString::fromUtf8("Update_Constants"));
        Update_Constants->setGeometry(QRect(50, 360, 141, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 973, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "P1", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "P2", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "P3", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "I1", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "I3", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "D1", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "D2", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "D3", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "I2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Mositure Plant 1", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Mositure Plant 2", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Mositure Plant 3", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "PWM Plant 1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "PWM Plant 2", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "PWM Plant 3", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Oz of Water Today Plant 1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Oz of Water Today Plant 2", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Oz of Water Today Plant 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Comm String ", 0, QApplication::UnicodeUTF8));
        Update_Constants->setText(QApplication::translate("MainWindow", "Update Constants", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
