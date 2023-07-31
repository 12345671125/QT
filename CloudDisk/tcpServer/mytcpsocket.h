/*myTcpSocket类用于处理并响应客户端的请求*/

#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#pragma once
#include <QTcpSocket>
#include <QDebug>
#include "protocol.h"
#include "opedb.h"
#include <QFileInfoList>
#include <QFile>
#include <QVector>

class myTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    myTcpSocket();
    QString getName();
    void login(protocol::PDU* pdu);

    void showOnline(protocol::PDU* pdu);

    void searchUser(protocol::PDU* pdu);

    void addFriends(protocol::PDU* pdu);

    void handleFriRespond(protocol::PDU* pdu,int type);

    void handleFlushFriends(protocol::PDU* pdu);

    void handleDelFriend(protocol::PDU* pdu);

    void handlePrivateChat(protocol::PDU* pdu);

    void requestFault(protocol::PDU* pdu);

    void handlePublicChat(protocol::PDU* pdu);

    void handleCreateDir(protocol::PDU* pdu);

    void handleFlushFile(protocol::PDU* pdu);

    void handleDelDir(protocol::PDU* pdu);

    void handleDelFile(protocol::PDU* pdu);

    void handleReNameFile(protocol::PDU* pdu);

    void handleUploadFile(protocol::PDU* pdu);

    void handleGetUploadFileData(protocol::PDU* pdu);

    void handleUploadFileFin(protocol::PDU* pdu);
    void handleUploadFileInfo(protocol::PDU* pdu);


public slots:
    void recvMsg();//用于处理请求
    void regist(protocol::PDU* pdu);//用于处理注册
    void clientOffine();
    //    void respond(PDU* pdu); //用于回复

    //    void handleGetFOnlineStatus(PDU * pdu);
    //    void logout();
signals:
    void offline(myTcpSocket* mySocket);
private:
    QString m_strName;
    QFile* file = NULL;
    QString curPath;
};

#endif // MYTCPSOCKET_H
