#include "opewidget.h"

OpeWidget::OpeWidget(QWidget *parent) : QWidget(parent)
{
    this->m_pListW = new QListWidget(this);
    this->m_pListW->addItem("好友");
//    this->m_pListW->addItem("图书");
    m_pFriend = new Friend;

    m_pSW  = new QStackedWidget;
    m_pSW->addWidget(m_pFriend);
    QHBoxLayout* pMain = new QHBoxLayout;
    pMain->addWidget(m_pListW);
    pMain->addWidget(m_pSW);

    setLayout(pMain);
    QObject::connect(m_pListW,SIGNAL(currentRowChanged(int)),m_pSW,SLOT(setCurrentIndex(int)));
}

OpeWidget& OpeWidget::getinstance()
{
    static OpeWidget instance; //一个静态的OpeWidget 对象
    return instance;//返回这个对象的引用
}

Friend *OpeWidget::getFriend()
{
    return m_pFriend;
}
