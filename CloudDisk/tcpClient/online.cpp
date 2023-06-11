/*在线页面类*/

#include "online.h"
#include "ui_online.h"

Online::Online(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Online)
{
    ui->setupUi(this);
}

Online::~Online()
{
    delete ui;
}

void Online::showUser(PDU *pdu)
{
    if(pdu == NULL) return;
    uint uiSize = pdu->uiMsgLen/32;
    char caTmp[32];
    this->ui->online_lw->clear();
    for(uint i = 0;i<uiSize;i++){
        memcpy(caTmp,(char*)pdu->caMsg+i*32,32);
        this->ui->online_lw->addItem(caTmp);
    }

}

void Online::showSearchUser(PDU *pdu)
{
    if(pdu == NULL) return;
    uint uiSize = pdu->uiMsgLen/34;
    char caTmp[34];
    this->ui->online_lw->clear();
    for(uint i = 0;i<uiSize;i++){
        memcpy(caTmp,(char*)pdu->caMsg+i*34,34);
        this->ui->online_lw->addItem(caTmp);
    }
}
