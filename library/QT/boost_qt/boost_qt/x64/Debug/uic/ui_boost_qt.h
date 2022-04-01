/********************************************************************************
** Form generated from reading UI file 'boost_qt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOST_QT_H
#define UI_BOOST_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boost_qtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *boost_qtClass)
    {
        if (boost_qtClass->objectName().isEmpty())
            boost_qtClass->setObjectName(QString::fromUtf8("boost_qtClass"));
        boost_qtClass->resize(600, 400);
        menuBar = new QMenuBar(boost_qtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        boost_qtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(boost_qtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        boost_qtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(boost_qtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        boost_qtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(boost_qtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        boost_qtClass->setStatusBar(statusBar);

        retranslateUi(boost_qtClass);

        QMetaObject::connectSlotsByName(boost_qtClass);
    } // setupUi

    void retranslateUi(QMainWindow *boost_qtClass)
    {
        boost_qtClass->setWindowTitle(QCoreApplication::translate("boost_qtClass", "boost_qt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boost_qtClass: public Ui_boost_qtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOST_QT_H
