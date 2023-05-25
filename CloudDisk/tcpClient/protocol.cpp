#include "protocol.h"


PDU *createPDU(uint uiMsgLen)
{
    uint uiPDULen = sizeof(PDU)+uiMsgLen;
    PDU*  pdu = (PDU*)malloc(uiPDULen);
    if(pdu == nullptr)
        exit(EXIT_FAILURE);
    else
    memset(pdu,0,uiPDULen);
    pdu->uiPDULen = uiPDULen;
    pdu->uiMsgLen = uiMsgLen;
    return pdu;
}

PDU PDU::default_respond(uint Type,QString respondStr) //一个默认的回复模板
{
    PDU instance;
    instance.uiPDULen = sizeof(PDU);
    instance.uiMsgLen = 0;
    instance.uiMsgType = Type;
    memcpy(instance.caData,respondStr.toStdString().c_str(),respondStr.length());
    return instance;
}
