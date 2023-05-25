#include "opewidget.h"

OpeWidget::OpeWidget(QWidget *parent) : QWidget(parent)
{
    this->m_pListW = new QListWidget(this);
    this->m_pListW->addItem("好友");
    this->m_pListW->addItem("图书");
}
