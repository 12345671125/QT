#include "clientwin.h"
#include "ui_clientwin.h"

clientWin::clientWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clientWin)
{
    ui->setupUi(this);
    initconfig(); //初始化配置
    connectToServer();
    QObject::connect(&this->clientSocket,SIGNAL(connected()),this,SLOT(showConnected()));
}

//从配置文件中获取服务器ip和port
void clientWin::initconfig()
{
    QFile file(":/config");  //定义File对象 用来读取文件
    if(file.open(QIODevice::ReadOnly))//以只读方式打开文件
    {
       QByteArray byteArr =  file.readAll();//将配置文件中的内容读出，以二进制的形式储存在QByteArray中
       QString configData = QString::fromStdString(byteArr.toStdString());//将二进制数据转换为QString的形式
//       qDebug()<<configData;
       configData.replace("\r\n",";");
       QStringList strList = configData.split(";");
       for(int i = 0;i<strList.length();i++){ //遍历strList,截取ip和port
            strList[i]   = strList[i].mid(strList[i].indexOf("=")+1,-1);
//            qDebug()<<strList[i];
       }
       this->ip = strList[0];//将文件中读取的ip储存到ip中
       this->port = strList[1].toUShort();//将文件中读取的port储存到port中
       file.close();
    }else{
        QMessageBox::critical(this,"open config","open config fault!");
    }
}


//连接服务器
void clientWin::connectToServer(){
    this->clientSocket.connectToHost(QHostAddress(this->ip),this->port);  //连接服务器
}

void clientWin::showConnected(){
    QMessageBox::information(this,"connectToSercer","连接服务器成功!");
}

clientWin::~clientWin()
{
    delete ui;
}


void clientWin::on_sendButton_clicked()
{
    QString strMsg = this->ui->msgInput->text();
    if(!strMsg.isEmpty()){
            PDU *pdu = createPDU(strMsg.size()+1);
            pdu->uiMsgType = _msgText_;
            memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.size());
            this->clientSocket.write((char*) pdu, pdu->uiPDULen);
            free(pdu);
            pdu = nullptr;
    }else{
        QMessageBox::warning(this,"send Message","发送的信息不能为空!");
    }
}
