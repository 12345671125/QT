#include "clientwin.h"
#include "ui_clientwin.h"

ClientWin::ClientWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWin)
{
    ui->setupUi(this);
    this->status = false;
    this->localhostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localhostName);
    qDebug()<<this->localhostName;
    qDebug()<<info.addresses();
    QObject::connect(&this->tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    QObject::connect(&this->tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    QObject::connect(&this->tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    QObject::connect(&this->tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError()));
}

ClientWin::~ClientWin()
{
    delete ui;
}

void ClientWin::on_sendMsg_clicked()
{
    QString msg = this->address+": "+this->ui->msgInput->text();
    this->tcpSocket.write(msg.toUtf8());
    this->ui->msgInput->clear();
}
void ClientWin::onConnected(){
    this->status = true;
    this->ui->addressInput->setEnabled(false);
    this->ui->portInput->setEnabled(false);
    this->ui->sendMsg->setEnabled(true);
    //向服务器发送进入聊天室提示消息
    QHostInfo info = QHostInfo::fromName(localhostName);
    QList<QHostAddress> address = info.addresses();
    QString msg;
    for(QHostAddress address:info.addresses())
       {
           if(address.protocol()==QAbstractSocket::IPv4Protocol)
           {
              msg = address.toString() + "进入聊天室";
              this->address = address.toString();
           }
       }
    //toUtf8:QString转换QByteArray
    this->tcpSocket.write(msg.toUtf8());

} //和服务器连接成功时执行的槽函数
void ClientWin::onDisconnected(){

}//和服务器断开连接槽函数
void ClientWin::onReadyRead(){
        if(this->tcpSocket.bytesAvailable()){
            QByteArray buf = this->tcpSocket.readAll();
            this->ui->listWidget->addItem(buf);
            this->ui->listWidget->scrollToBottom();
        }
}//接收聊天消息的槽函数
void ClientWin::onError(){
    //获取网络异常的原因
    QMessageBox::critical(this,"ERROR",this->tcpSocket.errorString());
    this->ui->addressInput->setEnabled(true);
    this->ui->portInput->setEnabled(true);

}//网络执行异常的槽函数


void ClientWin::on_pushButton_clicked()
{
    if(this->status == false){
        this->serverIp.setAddress(this->ui->addressInput->text());
        this->serverPost = this->ui->portInput->text().toUShort();
        this->tcpSocket.connectToHost(this->serverIp,this->serverPost);
  //      qDebug()<<"connect";
    }else if(this->status == true){
        QString msg = this->address + "离开聊天室";
        this->tcpSocket.write(msg.toUtf8());
          this->tcpSocket.disconnectFromHost();
        this->ui->addressInput->setEnabled(true);
        this->ui->portInput->setEnabled(true);
        this->ui->sendMsg->setEnabled(false);
        this->status = false;
    }
}
