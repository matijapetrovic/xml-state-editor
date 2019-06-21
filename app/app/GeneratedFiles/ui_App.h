/********************************************************************************
** Form generated from reading UI file 'App.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppClass)
    {
        if (AppClass->objectName().isEmpty())
            AppClass->setObjectName(QString::fromUtf8("AppClass"));
        AppClass->resize(600, 400);
        centralWidget = new QWidget(AppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        AppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AppClass->setStatusBar(statusBar);

        retranslateUi(AppClass);

        QMetaObject::connectSlotsByName(AppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppClass)
    {
        AppClass->setWindowTitle(QCoreApplication::translate("AppClass", "App", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppClass: public Ui_AppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
