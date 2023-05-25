#include "mytcpsocket.h"

myTcpSocket::myTcpSocket()
{
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    QObject::connect(this,SIGNAL(disconnected()),this,SLOT(clientOffine()));
}

QString myTcpSocket::getName()
{
    return this->m_strName;
}

void myTcpSocket::recvMsg()
{
    uint uiPDULen = 0;
    this->read((char*)&uiPDULen,sizeof(uint)); //para1:数据存放的地址，para2:读出的数据大小，读出uint字节的大小，这个uint为总的数据大小
    uint uiMsgLen = uiPDULen - sizeof(PDU); //用总的数据大小减去PDU结构体的默认，获取实际消息长度
    PDU* pdu = createPDU(uiMsgLen); //创建协议结构体，用于接收数据
    this->read((char*)pdu + sizeof (uint),uiPDULen-sizeof (uint)); /*让指针偏移来读取剩下的数据大小,先将pdu的指针类型转换为了char类型的指针，
那么当指针指针加一的时候会向后偏移一个字节的大小*/
    switch (pdu->uiMsgType)
    {
        case ENUM_MSG_TYPE_REGIST_REQUEST:
        this->regist(pdu);
        break;

        case ENUM_MSG_TYPE_LOGIN_REQUEST:
        this->login(pdu);
        break;

        default: break;
    }
}

void myTcpSocket::regist(PDU* pdu)
{
    //    qDebug() << this->bytesAvailable(); //用 bytesAvailable 获取到客户端发送过来的字节数
        char password[64] = {"\n"};
        char username[64] = {"\n"};
        strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
        strncpy(password,pdu->caData+64,64);//从pdu.cadata中读取password
        bool ret = OpeDB::getInsance().handleRegit(username,password); //尝试将用户名密码写入数据库
        if(ret) //如果写入成功
        {
            PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_REGIST_RESPOND,REGIST_OK);
            qDebug() << pdu.caData;
            this->write((char*)&pdu,pdu.uiPDULen);
        }
        else   //如果写入失败
        {
            PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_REGIST_RESPOND,REGIST_FAILED);
            qDebug() << pdu.caData;
            this->write((char*)&pdu,pdu.uiPDULen);
        }
}

void myTcpSocket::clientOffine()
{
    OpeDB::getInsance().handleOffline(m_strName.toStdString().c_str());
    emit offline(this); //发送offine信号
}

void myTcpSocket::login(PDU *pdu)
{
    char password[64] = {"\n"};
    char username[64] = {"\n"};
    strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
    strncpy(password,pdu->caData+64,64);//从pdu.cadata中读取password
    bool ret = OpeDB::getInsance().handleLogin(username,password); //尝试登录
    if(ret) //如果登录成功
    {
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_LOGIN_RESPOND,LOGIN_OK);
        qDebug() << pdu.caData;
        this->write((char*)&pdu,pdu.uiPDULen);
        this->m_strName = username;
    }
    else   //如果登录失败
    {
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_LOGIN_RESPOND,LOGIN_FAILED);
        qDebug() << pdu.caData;
        this->write((char*)&pdu,pdu.uiPDULen);
    }

}
