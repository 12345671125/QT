/********************************************************************************
** Form generated from reading UI file 'loginregisterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINREGISTERDIALOG_H
#define UI_LOGINREGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <labelededit.h>

QT_BEGIN_NAMESPACE

class Ui_LoginRegisterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    LabeledEdit *usernameWidget;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    LabeledEdit *passwordWidget;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *LoginRegisterDialog)
    {
        if (LoginRegisterDialog->objectName().isEmpty())
            LoginRegisterDialog->setObjectName(QString::fromUtf8("LoginRegisterDialog"));
        LoginRegisterDialog->resize(400, 300);
        LoginRegisterDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(LoginRegisterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(LoginRegisterDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/handle"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(60, 60));
        pushButton_3->setCheckable(false);
        pushButton_3->setAutoDefault(true);
        pushButton_3->setFlat(true);

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        usernameWidget = new LabeledEdit(LoginRegisterDialog);
        usernameWidget->setObjectName(QString::fromUtf8("usernameWidget"));
        usernameWidget->setMinimumSize(QSize(200, 10));

        horizontalLayout_2->addWidget(usernameWidget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        passwordWidget = new LabeledEdit(LoginRegisterDialog);
        passwordWidget->setObjectName(QString::fromUtf8("passwordWidget"));
        passwordWidget->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(passwordWidget);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        loginButton = new QPushButton(LoginRegisterDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout_4->addWidget(loginButton);

        registerButton = new QPushButton(LoginRegisterDialog);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        horizontalLayout_4->addWidget(registerButton);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(LoginRegisterDialog);

        QMetaObject::connectSlotsByName(LoginRegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginRegisterDialog)
    {
        LoginRegisterDialog->setWindowTitle(QCoreApplication::translate("LoginRegisterDialog", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LoginRegisterDialog", "QooMusic", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginRegisterDialog", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginRegisterDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginRegisterDialog: public Ui_LoginRegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINREGISTERDIALOG_H
