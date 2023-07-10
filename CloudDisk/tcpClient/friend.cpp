/*好友界面类*/
#pragma execution_character_set("utf-8")
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
    this->m_pSearchUserPB->setDisabled(true);
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

    this->flushFriends();

/*设置刷新好友定时器*/
    this->m_Timer = new QTimer(this);
    m_Timer->setInterval(5000);
//    m_Timer->start();

    QObject::connect(m_pShowOnlineUserPB,SIGNAL(clicked(bool)),this,SLOT(showOnline()));
    QObject::connect(m_pSearchUserPB,SIGNAL(clicked(bool)),this,SLOT(searchUser()));

    QObject::connect(m_Timer,SIGNAL(timeout()),this,SLOT(flushFriends()));
    QObject::connect(m_pFlushFriendPB,SIGNAL(clicked(bool)),this,SLOT(flushFriends()));

    QObject::connect(m_pDelFriendPB,SIGNAL(clicked(bool)),this,SLOT(deleteFriend()));


}

Friend::~Friend()
{
    this->m_Timer->stop();
    delete this->m_Timer;
}

void Friend::showAllOnlineUser(PDU* pdu)
{
    if(pdu == NULL) return;
    this->online->showUser(pdu);

}

void Friend::showSearchUser(PDU *pdu)
{
    if(pdu == NULL) return;
    this->online->showSearchUser(pdu);
}

void Friend::updateFriend(PDU *pdu)
{
    this->m_pFriendListWidget->clear(); //清空现有好友队列
    if(NULL == pdu){
        return;
    }
    uint uiSize = pdu->uiMsgLen / 64;
    char caName[64] = {'\0'};
    for(uint i = 0;i<uiSize;i++){
        memcpy(caName,((char*)pdu->caMsg)+(i*64),64);
        this->m_pFriendListWidget->addItem(caName);
//        qDebug()<<caName;
    }
}

void Friend::showOnline()
{
    this->m_pSearchUserPB->setDisabled(false);
    if(online -> isHidden()){
         online->show();
         PDU pdu = PDU::default_request(ENUM_MSG_TYPE_ALL_ONLINE_REQUEST,"在线用户请求");
         clientWin::getInstance().getTcpSocket().write((char*)&pdu,pdu.uiPDULen);
    }
    else
         online->hide();
}

void Friend::searchUser()
{
    QString userName  = QInputDialog::getText(this,"搜索","用户名:");
    if(!userName.isEmpty())
    {
//         qDebug() << userName;
         PDU  pdu = PDU::default_request(ENUM_MSG_TYPE_SEARCHUSER_REQUEST,userName.toStdString().c_str());
         clientWin::getInstance().getTcpSocket().write((char*)&pdu,pdu.uiPDULen);
    }
}

void Friend::flushFriends()
{
    PDU pdu = PDU::default_request(ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST,clientWin::getInstance().getLoginName());
    clientWin::getInstance().getTcpSocket().write((char*)&pdu,pdu.uiPDULen);
}

void Friend::deleteFriend()
{
    QString curName = OpeWidget::getinstance().getFriend()->m_pFriendListWidget->currentItem()->text(); //获取当前选中的好友用户名

    if(QMessageBox::information(this,"删除好友","确定要删除好友"+curName+"?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
    /*向服务器发送删除好友请求*/
    PDU pdu = PDU::default_request(ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST,curName+clientWin::getInstance().getLoginName());
    clientWin::getInstance().getTcpSocket().write((char*)&pdu,pdu.uiPDULen);
}



}
