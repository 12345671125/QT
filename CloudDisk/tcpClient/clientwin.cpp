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

//#if 0
//void clientWin::on_sendButton_clicked()
//{
//    QString strMsg = this->ui->msgInput->text();
//    if(!strMsg.isEmpty()){
//            PDU *pdu = createPDU(strMsg.size()+1);
//            pdu->uiMsgType = _msgText_;
//            memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.size());
//            this->clientSocket.write((char*) pdu, pdu->uiPDULen);
//            free(pdu);
//            pdu = nullptr;
//    }else{
//        QMessageBox::warning(this,"send Message","发送的信息不能为空!");
//    }
//}
//#endif

void clientWin::on_login_clicked()
{

}

void clientWin::on_regist_clicked()
{
    if(!this->ui->usernameInput->text().isEmpty() && !this->ui->passwordInput->text().isEmpty()){
        QString username = this->ui->usernameInput->text();
        QString password = this->ui->passwordInput->text();
        QByteArray bytePwdMd5 = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5);
        password = bytePwdMd5.toHex();
        qDebug()<<password;
        PDU* pdu = createPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_REGIST_REQUEST;
        strncpy(pdu->caData,username.toStdString().c_str(),64); //先将QString 转换成 标准C++字符串 ，再转换为C风格的字符数组
        strncpy(pdu->caData+64,password.toStdString().c_str(),64); //先将QString 转换成 标准C++字符串 ，再转换为C风格的字符数组
        this->clientSocket.write((char*)pdu, pdu->uiPDULen);
        free(pdu);
        pdu = nullptr;
    }else{
        QMessageBox::critical(this,"ERROR","用户名或密码不能为空!");
    }

}

void clientWin::on_logout_clicked()
{

}
