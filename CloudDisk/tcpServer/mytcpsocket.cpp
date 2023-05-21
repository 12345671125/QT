#include "mytcpsocket.h"

myTcpSocket::myTcpSocket()
{
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
}

void myTcpSocket::recvMsg()
{
    qDebug() << this->bytesAvailable(); //用 bytesAvailable 获取到客户端发送过来的字节数
    uint uiPDULen = 0;
    this->read((char*)&uiPDULen,sizeof(uint)); //先获取信息的总大小
    uint uiMsgLen = uiPDULen - sizeof(PDU); //获取实际消息长度
    PDU* pdu = createPDU(uiMsgLen); //创建协议结构体
    this->read((char*)pdu + sizeof (uint),uiPDULen-sizeof (uint)); /*让指针偏移来读取剩下的数据大小,先将pdu的指针类型转换为了char类型的指针，
那么当指针指针加一的时候会向后偏移一个字节的大小*/
    qDebug() << pdu->uiMsgType << (char*)(pdu->caMsg);
}
