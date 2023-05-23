#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>
#include <QDebug>
#include "protocol.h"
#include "opedb.h"

class myTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    myTcpSocket();
public slots:
    void recvMsg();//用于处理请求
    void regist(PDU* pdu);//用于处理注册
    void respond(PDU* pdu); //用于回复
//    void login();
//    void logout();
};

#endif // MYTCPSOCKET_H
