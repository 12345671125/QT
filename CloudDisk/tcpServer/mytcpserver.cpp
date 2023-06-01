/*myTcpServer类用于生成tcpServer并且监听并接受新的客户端请求*/

#include "mytcpserver.h"


myTcpServer::myTcpServer()
{

}

myTcpServer &myTcpServer::getInstance()
{
      static myTcpServer instance;     //创建静态myTcpServer对象 instance
      return instance;  //返回 静态对象 instance , 因为为静态的所以不管调用多少次都只产生一个
}

void myTcpServer::incomingConnection(qintptr handle)  /*当服务器端监听到客户端的请求时，会触发incomingConnection函数，
产生一个连接socket，服务器端通过这个socket与客户端进行通行*/
{
    qDebug()<<"new connect!";
    myTcpSocket* socket = new myTcpSocket();
    socket->setSocketDescriptor(handle); //qt产生的socket描述符放入自己的socket中
    this->socketList.push_back(socket); //将socket推入List

    QObject:: connect(socket,SIGNAL(offline(myTcpSocket*)),this,SLOT(deleteSocket(myTcpSocket*)));
}

void myTcpServer::deleteSocket(myTcpSocket *mySocket)
{
    QList<myTcpSocket*>::iterator iter = socketList.begin(); //创建迭代器
    for(;iter != socketList.end();iter++){
        if(mySocket == *iter){
            (*iter)->deleteLater();//释放空间
            *iter = NULL;
            socketList.erase(iter);
            break;
        }
    }
    for(int i = 0;i<this->socketList.size();i++){
        qDebug() << socketList.at(i)->getName();
    }
}
