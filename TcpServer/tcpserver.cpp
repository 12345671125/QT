#include "tcpserver.h"
#include "ui_tcpserver.h"
#include "m_tcpserver.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    this->loadConfig();
    m_TcpServer::getInstance().listen(QHostAddress(this->m_strIP),this->m_usPort);
}

void TcpServer::loadConfig()
{
    QFile file(":/server.config");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"open config","open config falled!");
        return;
    }
   QByteArray byteArr =  file.readAll();
   QString strData = byteArr.toStdString().c_str();//将二进程文件转成字符串再转成C的字符数组
   strData = strData.replace("\r\n"," ");//替换strData字符串中的“\r\n”为“ ”
   QStringList strList = strData.split(" ");//字符串分割
   this->m_strIP = strList.at(0);//at()函数获得数组下标为0的元素
   this->m_usPort = strList.at(1).toShort();//string 转 short
   qDebug() <<"ip:" << this->m_strIP <<" port:"<<this->m_usPort<<endl;
   file.close();
}

TcpServer::~TcpServer()
{
    delete ui;
}

