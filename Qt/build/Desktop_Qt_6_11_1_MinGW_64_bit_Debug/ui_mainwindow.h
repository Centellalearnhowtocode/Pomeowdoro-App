/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *PomewdoroApp;
    QLabel *Catlogo;
    QPushButton *Getstarted;
    QPushButton *Alreadyhaveanaccunt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setMinimumSize(QSize(1920, 10));
        MainWindow->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        PomewdoroApp = new QLabel(centralwidget);
        PomewdoroApp->setObjectName("PomewdoroApp");
        PomewdoroApp->setGeometry(QRect(530, 180, 331, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Kantumruy")});
        font.setPointSize(26);
        font.setBold(true);
        PomewdoroApp->setFont(font);
        Catlogo = new QLabel(centralwidget);
        Catlogo->setObjectName("Catlogo");
        Catlogo->setGeometry(QRect(160, 80, 311, 281));
        Catlogo->setMinimumSize(QSize(0, 10));
        Catlogo->setBaseSize(QSize(20, 0));
        Catlogo->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Sovannchornay Loy/Downloads/cat.png")));
        Catlogo->setScaledContents(true);
        Getstarted = new QPushButton(centralwidget);
        Getstarted->setObjectName("Getstarted");
        Getstarted->setGeometry(QRect(360, 443, 391, 41));
        QFont font1;
        font1.setPointSize(18);
        Getstarted->setFont(font1);
        Getstarted->setAutoFillBackground(false);
        Alreadyhaveanaccunt = new QPushButton(centralwidget);
        Alreadyhaveanaccunt->setObjectName("Alreadyhaveanaccunt");
        Alreadyhaveanaccunt->setGeometry(QRect(360, 500, 391, 41));
        Alreadyhaveanaccunt->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PomewdoroApp->setText(QCoreApplication::translate("MainWindow", "Pomeowdoro App", nullptr));
        Catlogo->setText(QString());
        Getstarted->setText(QCoreApplication::translate("MainWindow", "Get Start for Free", nullptr));
        Alreadyhaveanaccunt->setText(QCoreApplication::translate("MainWindow", "Already have an account?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
