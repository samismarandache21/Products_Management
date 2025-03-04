/********************************************************************************
** Form generated from reading UI file 'produse.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUSE_H
#define UI_PRODUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_produseClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *produseClass)
    {
        if (produseClass->objectName().isEmpty())
            produseClass->setObjectName("produseClass");
        produseClass->resize(600, 400);
        menuBar = new QMenuBar(produseClass);
        menuBar->setObjectName("menuBar");
        produseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(produseClass);
        mainToolBar->setObjectName("mainToolBar");
        produseClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(produseClass);
        centralWidget->setObjectName("centralWidget");
        produseClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(produseClass);
        statusBar->setObjectName("statusBar");
        produseClass->setStatusBar(statusBar);

        retranslateUi(produseClass);

        QMetaObject::connectSlotsByName(produseClass);
    } // setupUi

    void retranslateUi(QMainWindow *produseClass)
    {
        produseClass->setWindowTitle(QCoreApplication::translate("produseClass", "produse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class produseClass: public Ui_produseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUSE_H
