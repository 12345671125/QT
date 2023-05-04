#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include<QHostAddress>
tcpClient::tcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcpClient)
{
    ui->setupUi(this);
    this->loadConfig();
    connectServer();
    connect(&(tcpClient::m_tcpSocket),SIGNAL(connected()),this,SLOT(tcpClient::hasConnect));
}

tcpClient::~tcpClient()
{
    delete ui;
}

void tcpClient::loadConfig()
{
    QFile file(":/client.config");
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
bool tcpClient::connectServer(){

    this->m_tcpSocket.connectToHost(QHostAddress(this->m_strIP),this->m_usPort);

    return true;
}

void tcpClient::hasConnect()
{
//    QMessageBox::information(this,"消息","连接服务器成功");
    qDebug()<<"服务器连接成功!"<<endl;
    return;
}

