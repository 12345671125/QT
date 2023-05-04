#include "widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("First");
    this->resize(800,600);
//    QPushButton *button = new QPushButton();
    QPushButton* button1 = new QPushButton(this);
    button1->move(100,200);
    button1->setText("第二个按钮");
    button1->setParent(this);
    button1->show();
   connect(button1,&QPushButton::click,this,&QWidget::close);
}

Widget::~Widget()
{
}

