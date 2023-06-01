/*protocol类为协议类，规定cs端之间的通信细节，用于cs端传输数据*/

#include "protocol.h"


PDU *createPDU(uint uiMsgLen)
{
    uint uiPDULen = sizeof(PDU)+uiMsgLen; //协议总长(数据长度加原始协议长)
    PDU*  pdu = (PDU*)malloc(uiPDULen); //生成pdu协议对象
    if(pdu == nullptr)  //防御性编程 如果内存空间不足，退出程序
        exit(EXIT_FAILURE);
    else
    memset(pdu,0,uiPDULen); //初始化协议

    pdu->uiPDULen = uiPDULen; //将协议总长写入协议
    pdu->uiMsgLen = uiMsgLen;//将数据总长写入协议
    return pdu;
}
PDU PDU::default_request(uint Type,QString requestStr,uint MsgSize) //一个默认的请求模板，用于发送文字提示类请求
{
    PDU instance;
    instance.uiPDULen = sizeof(PDU);
    instance.uiMsgLen = MsgSize;
    instance.uiMsgType = Type;
    memcpy(instance.caData,requestStr.toStdString().c_str(),requestStr.length());
    return instance;
}
PDU PDU::default_respond(uint Type,QString respondStr,uint MsgSize) //一个默认的回复模板，用于发送文字提示类回复
{
    PDU instance;
    instance.uiPDULen = sizeof(PDU);
    instance.uiMsgLen = MsgSize;
    instance.uiMsgType = Type;
    memcpy(instance.caData,respondStr.toStdString().c_str(),respondStr.length()+1);
    return instance;
}


