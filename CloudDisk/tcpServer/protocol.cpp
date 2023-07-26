/*protocol类为协议类，规定cs端之间的通信细节，用于cs端传输数据*/

#include "protocol.h"
#include <QDebug>

protocol::PDU *protocol::createPDU(uint uiMsgLen)
{
    uint PDULen = sizeof(protocol::PDU)+uiMsgLen; //协议总长(数据长度加原始协议长)
    protocol::PDU*  pdu = (protocol::PDU*)malloc(PDULen); //生成pdu协议对象
    if(pdu == nullptr)  //防御性编程 如果内存空间不足，退出程序
        exit(EXIT_FAILURE);
    else
        memset(pdu,0,PDULen); //初始化协议

    pdu->PDULen = PDULen; //将协议总长写入协议
    pdu->uiMsgLen = uiMsgLen;//将数据总长写入协议
    return pdu;
}
protocol::PDU protocol::PDU::default_request(uint Type,QString requestStr,uint MsgSize) //一个默认的请求模板，用于发送文字提示类请求
{
    protocol::PDU instance;
    instance.PDULen = sizeof(protocol::PDU);
    instance.uiMsgLen = MsgSize;
    instance.uiMsgType = Type;
    memcpy(instance.caData,requestStr.toStdString().c_str(),requestStr.length());
    return instance;
}

protocol::PDU protocol::PDU::default_respond(uint Type,QString respondStr,uint MsgSize) //一个默认的回复模板，用于发送文字提示类回复
{
    protocol::PDU instance;
    instance.PDULen = sizeof(protocol::PDU);
    instance.uiMsgLen = MsgSize;
    instance.uiMsgType = Type;
    respondStr.append('\0');
    memcpy(instance.caData,respondStr.toStdString().c_str(),respondStr.length());
    return instance;
}



protocol::FileInfo protocol::createFileInfo(const int iFileType, const char *caFileName, const qint64 FileSize)
{
    protocol::FileInfo fileInfo;
    fileInfo.iFileType = iFileType;
    memcpy(fileInfo.caFileName,caFileName,64);
    fileInfo.FileSize = FileSize;
    return fileInfo;
}

protocol::FileInfoList* protocol::createFileInfoList(int length)
{
    protocol::FileInfoList*fileInfoList = (protocol::FileInfoList*)malloc(sizeof(protocol::FileInfoList));
    fileInfoList->FileListLength = length;
    fileInfoList->FileListSize = length * sizeof(protocol::FileInfo);
    fileInfoList->structSize = sizeof(protocol::FileInfoList) + fileInfoList->FileListSize;
    return fileInfoList;
}
