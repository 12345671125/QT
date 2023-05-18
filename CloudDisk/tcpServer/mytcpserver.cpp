#include "mytcpserver.h"

myTcpServer::myTcpServer()
{

}

myTcpServer &myTcpServer::getInstance()
{
      static myTcpServer instance;     //创建静态myTcpServer对象 instance
      return instance;  //返回 静态对象 instance , 因为为静态的所以不管调用多少次都只产生一个
}

void myTcpServer::incomingConnection(qintptr handle)
{
    qDebug()<<"new connect!";
}
