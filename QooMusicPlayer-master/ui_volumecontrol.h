/********************************************************************************
** Form generated from reading UI file 'volumecontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMECONTROL_H
#define UI_VOLUMECONTROL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_volumecontrol
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSlider *volume_Slider;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *volume_Button;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *volumecontrol)
    {
        if (volumecontrol->objectName().isEmpty())
            volumecontrol->setObjectName(QString::fromUtf8("volumecontrol"));
        volumecontrol->resize(54, 233);
        volumecontrol->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(volumecontrol);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 11, 0, 11);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        volume_Slider = new QSlider(volumecontrol);
        volume_Slider->setObjectName(QString::fromUtf8("volume_Slider"));
        volume_Slider->setStyleSheet(QString::fromUtf8("QSlider\n"
"{\n"
"    border-color: #cbcbcb;\n"
"}\n"
"QSlider::groove:vertical \n"
"{ \n"
"	background: #cbcbcb;\n"
"	width: 6px;\n"
"	border-radius: 1px;\n"
"	padding-left:-1px;\n"
"	padding-right:-1px;\n"
"	padding-top:-1px;\n"
"	padding-bottom:-1px; \n"
"}\n"
"QSlider::sub-page:vertical\n"
"{ \n"
"	background: #cbcbcb; \n"
"	border-radius: 2px; \n"
"} \n"
"QSlider::add-page:vertical\n"
" { \n"
"	background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #439cf4, stop:1 #439cf4); \n"
"	background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1, stop: 0 #439cf4, stop: 1 #439cf4); \n"
"	width: 10px; \n"
"	border-radius: 2px; \n"
"}\n"
"QSlider::handle:vertical \n"
"{\n"
"	border-image:url(:/icon/handle);\n"
"	margin: -2px -7px -2px -7px; \n"
"	height: 17px; \n"
"} "));
        volume_Slider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(volume_Slider);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        volume_Button = new QPushButton(volumecontrol);
        volume_Button->setObjectName(QString::fromUtf8("volume_Button"));
        volume_Button->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/sound"), QSize(), QIcon::Normal, QIcon::Off);
        volume_Button->setIcon(icon);
        volume_Button->setFlat(true);

        horizontalLayout_2->addWidget(volume_Button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(volumecontrol);

        QMetaObject::connectSlotsByName(volumecontrol);
    } // setupUi

    void retranslateUi(QDialog *volumecontrol)
    {
        volumecontrol->setWindowTitle(QCoreApplication::translate("volumecontrol", "Dialog", nullptr));
        volume_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class volumecontrol: public Ui_volumecontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMECONTROL_H
