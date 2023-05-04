#include "m_tcpserver.h"
#include <QDebug>//类似于cout
m_TcpServer::m_TcpServer()
{

}

m_TcpServer &m_TcpServer::getInstance()
{
    static m_TcpServer instance;
    return instance;
}

void m_TcpServer::incomingConnection(qintptr socketDescript)
{
    qDebug()<<"new client connected"<<endl;
}
