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

