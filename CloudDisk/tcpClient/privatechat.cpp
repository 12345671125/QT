#include "privatechat.h"
#include "ui_privatechat.h"
#include "protocol.h"
#include <QMessageBox>
#include "clientwin.h"

PrivateChat::PrivateChat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrivateChat)
{
    ui->setupUi(this);
    this->setWindowTitle("私聊对话框");
}

PrivateChat::~PrivateChat()
{
    delete ui;
}

void PrivateChat::setChatName(QString strName)
{
    this->m_strChatName = strName;
    ui->nameLabel->setText(this->m_strChatName);
    if(strName.mid(strName.length()-2,strName.length()-1) == "离线")
        this->ui->sendPtn->setDisabled(true);
    else
        this->ui->sendPtn->setDisabled(false);
    if(this->m_strChatName.isEmpty()){
        QMessageBox::critical(this,"error","遇到未知错误!");
        this->setAttribute(Qt::WA_DeleteOnClose,true);
        this->close();
    }
//    qDebug()<<strName;
}

PrivateChat &PrivateChat::getInstance()
{
    static PrivateChat instance;
    return instance;
}

void PrivateChat::on_sendPtn_clicked()
{
    QString strMsg = ui->inputEdit->text();
    if(!strMsg.isEmpty()){
        PDU *pdu = createPDU(strMsg.size()+1);
        pdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST;
        memcpy(pdu->caData,clientWin::getInstance().getLoginName().toStdString().c_str(),64);
        memcpy(pdu->caData+64,this->m_strChatName.toStdString().c_str(),64);
        memcpy((char*)pdu->caMsg,strMsg.toStdString().c_str(),strMsg.length());
        clientWin::getInstance().getTcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = nullptr;

    }else{
        QMessageBox::warning(this,"私聊","发送的聊天信息不能为空");
    }
}

