/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Feb 20 21:13:19 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *EarthTemplineEdit;
    QLabel *label_2;
    QLineEdit *WindTemplineEdit;
    QLabel *label_4;
    QLineEdit *WaterlineEdit;
    QLabel *label_5;
    QLineEdit *FirelineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *rawdataEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *EarthDutylineEdit;
    QLabel *label_7;
    QLineEdit *WindDutylineEdit;
    QLabel *label_8;
    QLineEdit *UnixTimelineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 100, 448, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        EarthTemplineEdit = new QLineEdit(horizontalLayoutWidget);
        EarthTemplineEdit->setObjectName(QString::fromUtf8("EarthTemplineEdit"));
        EarthTemplineEdit->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(EarthTemplineEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        WindTemplineEdit = new QLineEdit(horizontalLayoutWidget);
        WindTemplineEdit->setObjectName(QString::fromUtf8("WindTemplineEdit"));
        WindTemplineEdit->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(WindTemplineEdit);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        WaterlineEdit = new QLineEdit(horizontalLayoutWidget);
        WaterlineEdit->setObjectName(QString::fromUtf8("WaterlineEdit"));

        horizontalLayout->addWidget(WaterlineEdit);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        FirelineEdit = new QLineEdit(horizontalLayoutWidget);
        FirelineEdit->setObjectName(QString::fromUtf8("FirelineEdit"));

        horizontalLayout->addWidget(FirelineEdit);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 0, 341, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        rawdataEdit = new QLineEdit(horizontalLayoutWidget_2);
        rawdataEdit->setObjectName(QString::fromUtf8("rawdataEdit"));

        horizontalLayout_2->addWidget(rawdataEdit);

        horizontalLayoutWidget_3 = new QWidget(centralWidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(70, 200, 448, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        EarthDutylineEdit = new QLineEdit(horizontalLayoutWidget_3);
        EarthDutylineEdit->setObjectName(QString::fromUtf8("EarthDutylineEdit"));
        EarthDutylineEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(EarthDutylineEdit->sizePolicy().hasHeightForWidth());
        EarthDutylineEdit->setSizePolicy(sizePolicy);
        EarthDutylineEdit->setMaximumSize(QSize(50, 20));
        EarthDutylineEdit->setMaxLength(3);
        EarthDutylineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(EarthDutylineEdit);

        label_7 = new QLabel(horizontalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        WindDutylineEdit = new QLineEdit(horizontalLayoutWidget_3);
        WindDutylineEdit->setObjectName(QString::fromUtf8("WindDutylineEdit"));
        WindDutylineEdit->setMaximumSize(QSize(50, 20));

        horizontalLayout_3->addWidget(WindDutylineEdit);

        label_8 = new QLabel(horizontalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        UnixTimelineEdit = new QLineEdit(horizontalLayoutWidget_3);
        UnixTimelineEdit->setObjectName(QString::fromUtf8("UnixTimelineEdit"));

        horizontalLayout_3->addWidget(UnixTimelineEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Earth Tem", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Wind Temp", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Water Level", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Fire", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Comm String", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Earth Duty", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Wind Duty", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
