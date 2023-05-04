/********************************************************************************
** Form generated from reading UI file 'ernie.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERNIE_H
#define UI_ERNIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ernie
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Ernie)
    {
        if (Ernie->objectName().isEmpty())
            Ernie->setObjectName(QString::fromUtf8("Ernie"));
        Ernie->resize(416, 277);
        centralwidget = new QWidget(Ernie);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        Ernie->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Ernie);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 416, 21));
        Ernie->setMenuBar(menubar);
        statusbar = new QStatusBar(Ernie);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Ernie->setStatusBar(statusbar);

        retranslateUi(Ernie);

        QMetaObject::connectSlotsByName(Ernie);
    } // setupUi

    void retranslateUi(QMainWindow *Ernie)
    {
        Ernie->setWindowTitle(QCoreApplication::translate("Ernie", "Ernie", nullptr));
        pushButton->setText(QCoreApplication::translate("Ernie", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ernie: public Ui_Ernie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERNIE_H
