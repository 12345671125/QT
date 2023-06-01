/*好友界面类*/

#include "friend.h"
#include "protocol.h"
#include "clientwin.h"

Friend::Friend(QWidget *parent) : QWidget(parent)
{
    this->m_pShowMsgTE = new QTextEdit(this);
    this->m_pFriendListWidget = new QListWidget;
    this->m_pInputMsgLE = new QLineEdit;

    this->m_pDelFriendPB = new QPushButton("删除");
    this->m_pFlushFriendPB = new QPushButton("刷新");
    this->m_pShowOnlineUserPB = new QPushButton("显示在线用户");
    this->m_pSearchUserPB = new QPushButton("查询用户");
    this->m_pMsgSendPB = new QPushButton("信息发送");
    this->m_pPrivateChatPB = new QPushButton("私聊");

    QVBoxLayout *pLeftBL = new QVBoxLayout;
    pLeftBL->addWidget(m_pDelFriendPB);
    pLeftBL->addWidget(m_pFlushFriendPB);
    pLeftBL->addWidget(m_pShowOnlineUserPB);
    pLeftBL->addWidget(m_pSearchUserPB);
    pLeftBL->addWidget(m_pPrivateChatPB);

    QHBoxLayout* pTopHBL = new QHBoxLayout;
    pTopHBL->addWidget(m_pShowMsgTE);
    pTopHBL->addWidget(m_pFriendListWidget);
    pTopHBL->addLayout(pLeftBL);

    QHBoxLayout* pMsgHBL = new QHBoxLayout;
    pMsgHBL->addWidget(m_pInputMsgLE);
    pMsgHBL->addWidget(m_pMsgSendPB);

    QVBoxLayout* pMain = new QVBoxLayout;
    pMain->addLayout(pTopHBL);
    pMain->addLayout(pMsgHBL);

    online = new Online;
    pMain->addWidget(online);
    online->hide();
    setLayout(pMain);

    QObject::connect(m_pShowOnlineUserPB,SIGNAL(clicked(bool)),this,SLOT(showOnline()));
}

void Friend::showAllOnlineUser(PDU* pdu)
{
    if(pdu == NULL) return;
    this->online->showUser(pdu);

}

void Friend::showOnline()
{
    if(online -> isHidden()){
         online->show();
         PDU pdu = PDU::default_request(ENUM_MSG_TYPE_ALL_ONLINE_REQUEST,"在线用户请求");
         clientWin::getInstance().getTcpSocket().write((char*)&pdu,pdu.uiPDULen);
    }
    else
        online->hide();
}
