/********************************************************************************
** Form generated from reading UI file 'serverwin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIN_H
#define UI_SERVERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWin
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serverWin)
    {
        if (serverWin->objectName().isEmpty())
            serverWin->setObjectName(QString::fromUtf8("serverWin"));
        serverWin->resize(800, 600);
        centralwidget = new QWidget(serverWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        serverWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(serverWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        serverWin->setMenuBar(menubar);
        statusbar = new QStatusBar(serverWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        serverWin->setStatusBar(statusbar);

        retranslateUi(serverWin);

        QMetaObject::connectSlotsByName(serverWin);
    } // setupUi

    void retranslateUi(QMainWindow *serverWin)
    {
        serverWin->setWindowTitle(QCoreApplication::translate("serverWin", "serverWin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serverWin: public Ui_serverWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIN_H
