#ifndef M_TCPSERVER_H
#define M_TCPSERVER_H
#include<QTcpServer>

class m_TcpServer : public QTcpServer
{
    Q_OBJECT//对QT槽函数等的支持
public:
    m_TcpServer();
    static m_TcpServer& getInstance();
    void incomingConnection(qintptr socketDescript);
};

#endif // M_TCPSERVER_H
