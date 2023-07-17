/*好友界面类*/


#ifndef FRIEND_H
#define FRIEND_H
#pragma once
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "online.h"
#include "protocol.h"
#include <QInputDialog>
#include <QDebug>
#include <QTimer>


class Friend : public QWidget
{
    Q_OBJECT
public:
    explicit Friend(QWidget *parent = nullptr);
    ~Friend();
    void showAllOnlineUser(PDU* pdu);
    void showSearchUser(PDU* pdu);
    void updateFriend(PDU* pdu);
    void showPublicChat(PDU *pdu);


signals:
public slots:
    void showOnline();//显示在线用户槽函数
    void searchUser(); //查找用户槽函数
    void flushFriends(); //刷新好友列表
    void deleteFriend(); //删除好友
    void privateChat(); //私聊
    void publicChat(); //群聊
private:
    QTextEdit* m_pShowMsgTE;
    QListWidget* m_pFriendListWidget;
    QLineEdit* m_pInputMsgLE;
    QPushButton* m_pDelFriendPB;
    QPushButton* m_pFlushFriendPB;
    QPushButton* m_pShowOnlineUserPB;
    QPushButton* m_pSearchUserPB;
    QPushButton* m_pMsgSendPB;
    QPushButton* m_pPrivateChatPB;


    QTimer* m_Timer; //这个定时器用与刷新好友P

    Online* online;
//    void getFOnlineStatus(); //获取好友在线状态
};

#endif // FRIEND_H
