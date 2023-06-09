/*myTcpSocket类用于处理并响应客户端的请求*/

#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#pragma once
#include <QTcpSocket>
#include <QDebug>
#include "protocol.h"
#include "opedb.h"

class myTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    myTcpSocket();
    QString getName();
public slots:
    void recvMsg();//用于处理请求
    void regist(PDU* pdu);//用于处理注册
    void clientOffine();
//    void respond(PDU* pdu); //用于回复
    void login(PDU* pdu);

    void showOnline(PDU* pdu);

    void searchUser(PDU* pdu);

    void addFriends(PDU* pdu);

    void handleFriRespond(PDU* pdu,int type);

    void handleFlushFriends(PDU* pdu);

    void handleDelFriend(PDU* pdu);
//    void logout();
signals:
    void offline(myTcpSocket* mySocket);
private:
    QString m_strName;
};

#endif // MYTCPSOCKET_H
