#include "serverwin.h"
#include "ui_serverwin.h"

serverWin::serverWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::serverWin)
{
    ui->setupUi(this);
    this->timer = new QTimer;
    QObject::connect(&this->tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection())); //当有客户端向服务器发送连接请求
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(timeOut()));
}

serverWin::~serverWin()
{
    delete ui;
    delete this->timer;
}

//创建服务器按钮对应的槽函数
void serverWin::on_createButton_clicked()
{
    //获取服务器端口
   this->port =  (quint16)this->ui->portInput->text().toShort();
    //获取服务器监听地址
    this->address = QHostAddress(this->ui->ipInput->text());
    //设置服务器监听的端口和IP地址
    if(this->tcpServer.listen(this->address,this->port) == true){
        qDebug() << "创建服务器成功";
        //禁用创建服务器窗口
        this->ui->createButton->setEnabled(false);
        this->ui->portInput->setEnabled(false);
        this->ui->ipInput->setEnabled(false);

        //开启定时器
        this->timer->start(3000);
    }else{
        qDebug()<<"创建服务器失败！";
    };
}

//响应客户端连接请求的槽函数
void serverWin::onNewConnection(){
    //获取和客户端通信的套接字
    QTcpSocket* tcpClient = this->tcpServer.nextPendingConnection();
    this->tcpClientList.push_back(tcpClient);
    this->ui->listWidget->addItem(tcpClient->peerAddress().toString());
    //当客户端向服务器发送消息时，通信套接字发送信号:readyRead
    QObject::connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
};

//接收客户端消息的槽函数
void serverWin::onReadyRead(){
    //遍历容器哪个客户端给服务器发送了消息
    for(int i = 0;i<this->tcpClientList.size();i++){
        if(tcpClientList.at(i)->state() == QAbstractSocket::ConnectedState){  //防御性编程
        //bytesAvaliable::获取当前套接字等待读取消息字节数
        //返回0表示没有消息
        if(this->tcpClientList.at(i)->bytesAvailable()){
            //读取消息并保存
            QByteArray buf  = tcpClientList.at(i)->readAll();
            //显示消息
            this->ui->listWidget->addItem(buf);
            this->ui->listWidget->scrollToBottom();
            //转发消息给所有在线客户端
            this->sendMessage(buf);
        }
      }
    }
};

//将聊天消息转发
void serverWin::sendMessage(const QByteArray& buf){
    for(int i = 0;i<tcpClientList.size();i++){
        if(tcpClientList.at(i)->state() == QAbstractSocket::ConnectedState){  //防御性编程
            tcpClientList.at(i)->write(buf);
        }
    }
};

//定时器
void serverWin::timeOut(){
    //遍历检查容器中保存的客户端通信的套接字是否已经断开连接，如果是就删除
    for(int i = 0;i<this->tcpClientList.size();i++){
        if(tcpClientList.at(i)->state() == QAbstractSocket::UnconnectedState){
                delete this->tcpClientList.at(i); //防止内存溢出
                this->tcpClientList.removeAt(i);
                i--;
        }
    }
}
