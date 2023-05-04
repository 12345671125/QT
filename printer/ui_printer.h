/********************************************************************************
** Form generated from reading UI file 'printer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTER_H
#define UI_PRINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Printer
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *prevBtn;
    QPushButton *nextBtn;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Printer)
    {
        if (Printer->objectName().isEmpty())
            Printer->setObjectName(QString::fromUtf8("Printer"));
        Printer->resize(732, 388);
        QFont font;
        font.setPointSize(20);
        Printer->setFont(font);
        centralwidget = new QWidget(Printer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
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

        prevBtn = new QPushButton(centralwidget);
        prevBtn->setObjectName(QString::fromUtf8("prevBtn"));

        horizontalLayout->addWidget(prevBtn);

        nextBtn = new QPushButton(centralwidget);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));

        horizontalLayout->addWidget(nextBtn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        Printer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Printer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 732, 21));
        Printer->setMenuBar(menubar);

        retranslateUi(Printer);

        QMetaObject::connectSlotsByName(Printer);
    } // setupUi

    void retranslateUi(QMainWindow *Printer)
    {
        Printer->setWindowTitle(QCoreApplication::translate("Printer", "\345\233\276\345\233\276\347\247\200", nullptr));
        prevBtn->setText(QCoreApplication::translate("Printer", "\344\270\212\344\270\200\345\274\240", nullptr));
        nextBtn->setText(QCoreApplication::translate("Printer", "\344\270\213\344\270\200\345\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Printer: public Ui_Printer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTER_H
