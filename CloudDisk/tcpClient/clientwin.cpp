/*主界面类，用于客户端初始化*/

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
    QObject::connect(&this->clientSocket,SIGNAL(readyRead()),this,SLOT(recvMsg()));
}

clientWin &clientWin::getInstance()
{
    static clientWin instance;
    return instance;
}

QTcpSocket &clientWin::getTcpSocket()
{
    return this->clientSocket;
}

QString clientWin::getLoginName()
{
    return this->m_strLoginName;
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
       configData.replace("\n",";");
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

void clientWin::recvMsg()
{
    uint uiPDULen = 0;
    this->clientSocket.read((char*)&uiPDULen,sizeof(uint)); //para1:数据存放的地址，para2:读出的数据大小，读出uint字节的大小，这个uint为总的数据大小
    uint uiMsgLen = uiPDULen - sizeof(PDU); //用总的数据大小减去PDU结构体的默认，获取实际消息长度
    PDU* pdu = createPDU(uiMsgLen); //创建协议结构体，用于接收数据
    this->clientSocket.read((char*)pdu + sizeof (uint),uiPDULen-sizeof (uint)); /*让指针偏移来读取剩下的数据大小,先将pdu的指针类型转换为了char类型的指针，
那么当指针指针加一的时候会向后偏移一个字节的大小*/
    switch (pdu->uiMsgType)
    {
        case ENUM_MSG_TYPE_REGIST_RESPOND:
    {
        qDebug() << pdu->caData;
        if(strcmp(pdu->caData,REGIST_OK) == 0){
            QMessageBox::information(this,"注册","注册成功");
        }else if(strcmp(pdu->caData,REGIST_FAILED) == 0){
            qDebug() << 1;
            QMessageBox::warning(this,"注册","注册失败，用户名重复");
        }
        break;
    }
        case ENUM_MSG_TYPE_LOGIN_RESPOND:
    {
        qDebug() << pdu->caData;
        if(strcmp(pdu->caData,LOGIN_OK) == 0){
            QMessageBox::information(this,"登录","LOGIN_OK");
            this->setWindowTitle("当前用户:"+this->m_strLoginName);
            OpeWidget::getinstance().show();
            OpeWidget::getinstance().setWindowTitle("当前用户:"+this->m_strLoginName);
            this->hide();
        }else if(strcmp(pdu->caData,LOGIN_FAILED) == 0){
            qDebug() << 1;
            QMessageBox::warning(this,"登录","用户名或密码错误");
        }
        break;
    }
        case ENUM_MSG_TYPE_ALL_ONLINE_RESPOND:
    {

        OpeWidget::getinstance().getFriend()->showAllOnlineUser(pdu);
        break;
    }
        case ENUM_MSG_TYPE_SEARCHUSER_RESPOND:
    {
        OpeWidget::getinstance().getFriend()->showSearchUser(pdu);
        break;
    }
        case ENUM_MSG_TYPE_ADDFRIEND_REQUEST:
    {
        char username[64] = {"\n"}; //创建username数组用于存放用户名
        memset(username,0,sizeof(username));
        strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
        int ret = QMessageBox::information(this,"好友请求",QString("%1 想要添加你为好友").arg(username),QMessageBox::Yes,QMessageBox::No);
        if(ret == QMessageBox::Yes)
        {
            PDU pdu = PDU::default_request(ENUM_MSG_TYPE_ADDFRIEND_AGREE,"0");
            memcpy(pdu.caData,username,64);
            memcpy(pdu.caData+64,this->m_strLoginName.toStdString().c_str(),64);
            this->clientSocket.write((char*)&pdu,pdu.uiPDULen);
        }else
        {
            PDU pdu = PDU::default_request(ENUM_MSG_TYPE_ADDFRIEND_REFUSE,this->getLoginName()+username);
            this->clientSocket.write((char*)&pdu,pdu.uiPDULen);
        }
        break;
    }
        case ENUM_MSG_TYPE_ADDFRIEND_RESPOND:
    {
        QMessageBox::information(this,"添加好友",pdu->caData);
        break;
    }
        case ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND:
        OpeWidget::getinstance().getFriend()->updateFriend(pdu);
        break;
        default: break;
    }
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
    if(!this->ui->usernameInput->text().isEmpty() && !this->ui->passwordInput->text().isEmpty()){
        QString username = this->ui->usernameInput->text();
        QString password = this->ui->passwordInput->text();
        QByteArray bytePwdMd5 = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5); //使用MD5对密码进行加密
        password = bytePwdMd5.toHex();//将加密后的结果转换为16进制
//        qDebug()<<password;
        PDU* pdu = createPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_REQUEST;
        strncpy(pdu->caData,username.toStdString().c_str(),64); //先将QString 转换成 标准C++字符串 ，再转换为C风格的字符数组
        strncpy(pdu->caData+64,password.toStdString().c_str(),64); //先将QString 转换成 标准C++字符串 ，再转换为C风格的字符数组
        this->clientSocket.write((char*)pdu, pdu->uiPDULen);
        this->m_strLoginName = username; //将用户名保存
        free(pdu);
        pdu = nullptr;
    }else{
        QMessageBox::critical(this,"ERROR","用户名或密码不能为空!");
    }
}

void clientWin::on_regist_clicked()
{
    if(!this->ui->usernameInput->text().isEmpty() && !this->ui->passwordInput->text().isEmpty()){
        QString username = this->ui->usernameInput->text();
        QString password = this->ui->passwordInput->text();
        QByteArray bytePwdMd5 = QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5); //使用MD5对密码进行加密
        password = bytePwdMd5.toHex();//将加密后的结果转换为16进制
//        qDebug()<<password;
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
