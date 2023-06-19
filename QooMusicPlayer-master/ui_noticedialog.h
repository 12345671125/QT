/********************************************************************************
** Form generated from reading UI file 'noticedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTICEDIALOG_H
#define UI_NOTICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NoticeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *Noticelabel;

    void setupUi(QDialog *NoticeDialog)
    {
        if (NoticeDialog->objectName().isEmpty())
            NoticeDialog->setObjectName(QString::fromUtf8("NoticeDialog"));
        NoticeDialog->resize(170, 55);
        verticalLayout = new QVBoxLayout(NoticeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Noticelabel = new QLabel(NoticeDialog);
        Noticelabel->setObjectName(QString::fromUtf8("Noticelabel"));

        verticalLayout->addWidget(Noticelabel);


        retranslateUi(NoticeDialog);

        QMetaObject::connectSlotsByName(NoticeDialog);
    } // setupUi

    void retranslateUi(QDialog *NoticeDialog)
    {
        NoticeDialog->setWindowTitle(QCoreApplication::translate("NoticeDialog", "Dialog", nullptr));
        Noticelabel->setText(QCoreApplication::translate("NoticeDialog", "QooMusic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoticeDialog: public Ui_NoticeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTICEDIALOG_H
