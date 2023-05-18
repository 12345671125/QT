#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    myTcpServer();

    static myTcpServer& getInstance(); //单例模式
    void incomingConnection(qintptr handle);
};

#endif // MYTCPSERVER_H
