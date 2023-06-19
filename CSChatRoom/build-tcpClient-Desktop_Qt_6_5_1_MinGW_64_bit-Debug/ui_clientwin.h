/********************************************************************************
** Form generated from reading UI file 'clientwin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIN_H
#define UI_CLIENTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *addressInput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *portInput;
    QHBoxLayout *horizontalLayout;
    QLineEdit *msgInput;
    QPushButton *sendMsg;
    QPushButton *pushButton;

    void setupUi(QMainWindow *ClientWin)
    {
        if (ClientWin->objectName().isEmpty())
            ClientWin->setObjectName("ClientWin");
        ClientWin->resize(612, 580);
        centralwidget = new QWidget(ClientWin);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(0, 500));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        addressInput = new QLineEdit(centralwidget);
        addressInput->setObjectName("addressInput");

        horizontalLayout_3->addWidget(addressInput);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        portInput = new QLineEdit(centralwidget);
        portInput->setObjectName("portInput");

        horizontalLayout_4->addWidget(portInput);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        msgInput = new QLineEdit(centralwidget);
        msgInput->setObjectName("msgInput");

        horizontalLayout->addWidget(msgInput);

        sendMsg = new QPushButton(centralwidget);
        sendMsg->setObjectName("sendMsg");
        sendMsg->setEnabled(false);

        horizontalLayout->addWidget(sendMsg);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        ClientWin->setCentralWidget(centralwidget);

        retranslateUi(ClientWin);

        QMetaObject::connectSlotsByName(ClientWin);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWin)
    {
        ClientWin->setWindowTitle(QCoreApplication::translate("ClientWin", "ClientWin", nullptr));
        label->setText(QCoreApplication::translate("ClientWin", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        addressInput->setText(QCoreApplication::translate("ClientWin", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("ClientWin", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        portInput->setText(QCoreApplication::translate("ClientWin", "8080", nullptr));
        sendMsg->setText(QCoreApplication::translate("ClientWin", "\345\217\221\351\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientWin", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWin: public Ui_ClientWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIN_H
