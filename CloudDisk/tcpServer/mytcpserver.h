#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include "mytcpsocket.h"
#include <QList> //引入QList 用来存放socket
class myTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    myTcpServer();

    static myTcpServer& getInstance(); //单例模式
    void incomingConnection(qintptr handle);
public slots:
    void deleteSocket(myTcpSocket* mySocket);
private:
    QList<myTcpSocket*> socketList; //模板类，socketList中的每一个元素时一个myTcpSocket类的实例化对象的指针
};

#endif // MYTCPSERVER_H
