/*myTcpSocket类用于处理并响应客户端的请求*/
#pragma execution_character_set("utf-8")
#include "mytcpsocket.h"
#include"mytcpserver.h"
#include <QDir>

myTcpSocket::myTcpSocket()
{
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    QObject::connect(this,SIGNAL(disconnected()),this,SLOT(clientOffine()));
    this->setSocketOption(QTcpSocket::KeepAliveOption,true);
}

QString myTcpSocket::getName()
{
    return this->m_strName;
}

void myTcpSocket::recvMsg()
{
    uint uiPDULen = 0;
    this->read((char*)&uiPDULen,sizeof(uint)); //para1:数据存放的地址，para2:读出的数据大小，读出uint字节的大小，这个uint为总的数据大小
    uint uiMsgLen = uiPDULen - sizeof(protocol::PDU); //用总的数据大小减去PDU结构体的默认，获取实际消息长度
    protocol::PDU* pdu = protocol::createPDU(uiMsgLen); //创建协议结构体，用于接收数据
    this->read((char*)pdu + sizeof (uint),uiPDULen-sizeof (uint)); /*让指针偏移来读取剩下的数据大小,先将pdu的指针类型转换为了char类型的指针，
那么当指针指针加一的时候会向后偏移一个字节的大小*/
    switch (pdu->uiMsgType)   //通过客户端传过来的协议中的消息类型来进行不同的处理
    {
        case protocol::ENUM_MSG_TYPE_REGIST_REQUEST:
        this->regist(pdu);  //处理注册
        break;

        case protocol::ENUM_MSG_TYPE_LOGIN_REQUEST:
        this->login(pdu); //处理登录
        break;

        case protocol::ENUM_MSG_TYPE_ALL_ONLINE_REQUEST:
        this->showOnline(pdu); //处理显示在线用户
        break;

        case protocol::ENUM_MSG_TYPE_SEARCHUSER_REQUEST:
        this->searchUser(pdu); //搜索用户
        break;


        case protocol::ENUM_MSG_TYPE_ADDFRIEND_REQUEST:
        this->addFriends(pdu); //添加用户
        break;

        case protocol::ENUM_MSG_TYPE_ADDFRIEND_AGREE:
        this->handleFriRespond(pdu,protocol::ENUM_MSG_TYPE_ADDFRIEND_AGREE);//同意添加用户
        break;

        case protocol::ENUM_MSG_TYPE_ADDFRIEND_REFUSE:
        this->handleFriRespond(pdu,protocol::ENUM_MSG_TYPE_ADDFRIEND_REFUSE); //拒绝添加用户
        break;

        case protocol::ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST: //刷新好友
        this->handleFlushFriends(pdu);
        break;

        case protocol::ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST: //删除好友
        this->handleDelFriend(pdu);
        break;


        case protocol::ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST: //私聊请求
        this->handlePrivateChat(pdu);
        break;

        case protocol::ENUM_MSG_TYPE_PUBLIC_CHAT_REQUEST:
        this->handlePublicChat(pdu);
        break;


        case protocol::ENUM_MSG_TYPE_CREATE_DIR_REQUEST:
        this->handleCreateDir(pdu);
        break;

        case protocol::ENUM_MSG_TYPE_FLUSH_FILE_REQUEST:
        this->handleFlushFile(pdu);
        break;

        default:
        this->requestFault(pdu);
        break;
    }
}

void myTcpSocket::regist(protocol::PDU* pdu)
{
    //    qDebug() << this->bytesAvailable(); //用 bytesAvailable 获取到客户端发送过来的字节数
        char password[64] = {"\n"};
        char username[64] = {"\n"};
        strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
        strncpy(password,pdu->caData+64,64);//从pdu.cadata中读取password
        bool ret = OpeDB::getInsance().handleRegit(username,password); //尝试将用户名密码写入数据库
        if(ret) //如果写入成功
        {
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_REGIST_RESPOND,REGIST_OK);
            qDebug() << pdu.caData;
            this->write((char*)&pdu,pdu.PDULen);
            QDir dir;
            if(dir.mkdir(QString("./%1").arg(username)))
                qDebug()<<"mkdir true";
            else
                qDebug()<<"mkdir false";
        }
        else   //如果写入失败
        {
            protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_REGIST_RESPOND,REGIST_FAILED);
            qDebug() << pdu.caData;
            this->write((char*)&pdu,pdu.PDULen);
        }
}

void myTcpSocket::clientOffine()
{
    OpeDB::getInsance().handleOffline(m_strName.toStdString().c_str()); //调用数据库方法
    emit offline(this); //发送offine信号
}

void myTcpSocket::login(protocol::PDU *pdu)
{
    char password[64] = {"\n"}; //创建password数组用于存放用户密码
    char username[64] = {"\n"}; //创建username数组用于存放用户名
    strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
    strncpy(password,pdu->caData+64,64);//从pdu.cadata中读取password
    bool ret = OpeDB::getInsance().handleLogin(username,password); //尝试登录
    if(ret) //如果登录成功
    {
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_LOGIN_RESPOND,LOGIN_OK); //通过默认回复模板产生pdu对象
        qDebug() << pdu.caData;
        this->write((char*)&pdu,pdu.PDULen);//将协议写入套接字
        this->m_strName = username;
    }
    else   //如果登录失败
    {
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_LOGIN_RESPOND,LOGIN_FAILED);//通过默认回复模板产生pdu对象
        qDebug() << pdu.caData;
        this->write((char*)&pdu,pdu.PDULen);//将协议写入套接字
    }

}

void myTcpSocket::showOnline(protocol::PDU* pdu)
{
    QStringList ret = OpeDB::getInsance().handleAllOnline(); //查询数据库获取在线用户信息，储存在字符串数组ret中
    uint uiMsgLen = ret.size()*32; //设置协议消息长度为在线用户长度
    protocol::PDU* respdu = protocol::createPDU(uiMsgLen);//生成传输协议对象，用来传输数据
    respdu->uiMsgType = protocol::ENUM_MSG_TYPE_ALL_ONLINE_RESPOND;//设置传输的消息类型
    for(int i = 0;i<ret.size();i++){ //使用循环将用户数据考入缓存区
        memcpy((char*)respdu->caMsg+i*32,ret.at(i).toStdString().c_str(),ret.at(i).size()); //每次向缓存区中拷入32个字节的内容并修改指针偏移量
    }
    write((char*)respdu,respdu->PDULen);//将协议内容写入套接字
    free(respdu); //释放缓存区
    respdu = NULL;//防止野指针
}

void myTcpSocket::searchUser(protocol::PDU *pdu)
{
    QStringList ret = OpeDB::getInsance().handleSearchUser(pdu->caData);
    uint uiMsgLen = ret.size()*32;
    qDebug()<<uiMsgLen;
    protocol::PDU* respdu = protocol::createPDU(uiMsgLen);
    respdu->uiMsgType = protocol::ENUM_MSG_TYPE_SEARCHUSER_RESPOND;
    for(int i = 0;i<ret.size();i++){
        memcpy((char*)respdu->caMsg+i*32,ret.at(i).toStdString().c_str(),ret.at(i).size());
    }
    write((char*)respdu,respdu->PDULen);
    free(respdu);
    respdu = NULL;
}

void myTcpSocket::addFriends(protocol::PDU *pdu)
{
    char pername[64] = {"\n"}; //创建password数组用于存放用户密码
    char username[64] = {"\n"}; //创建username数组用于存放用户名
    strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
    strncpy(pername,pdu->caData+64,64);//从pdu.cadata中读取pername
    int ret = OpeDB::getInsance().handleAddFriend(pername,username);
    if(ret == -1){
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"unkown error");
        write((char*)&pdu,pdu.PDULen);
    }else if(ret == 0){
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"friend existed");
        write((char*)&pdu,pdu.PDULen);

    }else if(ret == 1){
        myTcpServer::getInstance().FResend(pername,pdu);

    }else if(ret ==2){
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"user offine");
        write((char*)&pdu,pdu.PDULen);

    }else if(ret == 3){
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"user not existed");
        write((char*)&pdu,pdu.PDULen);

    }


}

void myTcpSocket::handleFriRespond(protocol::PDU *pdu,int type)
{
    if(type == protocol::ENUM_MSG_TYPE_ADDFRIEND_AGREE){
        char userName[64] = {"\n"};
        char perName[64] = {"\n"};
        memcpy(userName,pdu->caData,64);
        memcpy(perName,pdu->caData+64,64);
        qDebug()<<userName;
        qDebug()<<perName;
        OpeDB::getInsance().handleAddFriend(perName,userName,1);
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"对方同意");
        this->write((char*)&pdu,pdu.PDULen);
    }else if(type == protocol::ENUM_MSG_TYPE_ADDFRIEND_REFUSE){
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"对方拒绝");
        this->write((char*)&pdu,pdu.PDULen);
    }
}

void myTcpSocket::handleFlushFriends(protocol::PDU *pdu)
{
    char userName[64] = {"/n"};
    memcpy(userName,pdu->caData,64);
//    qDebug()<<userName;
    QStringList resultList = OpeDB::getInsance().handleFlushFriends(userName);
    uint msgLen = resultList.length();
//    qDebug()<<msgLen;
    protocol::PDU* sendPdu = protocol::createPDU(msgLen*64);
    sendPdu->uiMsgType = protocol::ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND;
    memcpy(sendPdu->caData,QString("success").toStdString().c_str(),8);
    int i = 0;
    while(i<resultList.length()){
        memcpy((char*)sendPdu->caMsg+(i*64),resultList[i].toStdString().c_str(),64);
//        qDebug()<<resultList[i].toStdString();
        i++;
    }
    this->write((char*)sendPdu,sendPdu->PDULen);
    delete sendPdu;
    sendPdu = nullptr;
}

void myTcpSocket::handleDelFriend(protocol::PDU *pdu)
{
    if(pdu == NULL) return;
    char pername[64] = {"/n"};
    char username[64] = {"/n"};
    memcpy(pername,(char*)pdu->caData,64);
    memcpy(username,((char*)pdu->caData)+64,64);
//    qDebug()<<pername;
//    qDebug()<<username;
    OpeDB::getInsance().handleDelFriend(username,pername);

}

void myTcpSocket::handlePrivateChat(protocol::PDU *pdu)
{
//    qDebug()<<"handlePrivateChat";
    char username[64] = {"\0"};
    char pername[64] = {"\0"};
    memcpy(username,pdu->caData,64);
    memcpy(pername,pdu->caData+64,64); //解析协议中的私聊对象名
    myTcpServer::getInstance().MsgResend(pername,pdu); //进行转发
}

void myTcpSocket::requestFault(protocol::PDU *pdu)
{
    protocol::PDU requestPdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_ERROR_RESPOND,"REQUESTFAULT!");
    this->write((char*)&requestPdu,requestPdu.PDULen);
}

void myTcpSocket::handlePublicChat(protocol::PDU *pdu)
{
    if(pdu == nullptr) return;
    char username[64] = {"\0"};
    memcpy(username,pdu->caData,64);
    QStringList resultList = OpeDB::getInsance().handleGetOnlineFriend(username);
    if(resultList.isEmpty()){
        QMessageBox::critical(NULL,"error","查询好友错误",QMessageBox::Ok);
        return;
    }
    myTcpServer::getInstance().MsgResend(resultList,pdu);


}

void myTcpSocket::handleCreateDir(protocol::PDU *pdu)
{
    QDir dir;
    QString strCurPath = QString("%1").arg((char*)(pdu->caMsg));
    bool ret = dir.exists(strCurPath);
    qDebug()<<strCurPath;
    if(ret){     //当前目录存在
        char caNewDir[64] = {"\0"};
        memcpy(caNewDir,pdu->caData+64,64);
        QString strNewPath = strCurPath + "/" + caNewDir;
        qDebug() << strNewPath;
        ret = dir.exists(strNewPath);
        qDebug() << ret;
        if(ret)  //创建的文件名已存在
        {
                protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_CREATE_DIR_RESPOND,FILE_NAME_EXIT);
                this->write((char*)&pdu,pdu.PDULen);
        }
        else  //创建的文件名不存在
        {
                dir.mkdir(strNewPath);
                protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_CREATE_DIR_RESPOND,CREATE_DIR_SUCESS);
                this->write((char*)&pdu,pdu.PDULen);

        }
    }
    else
    {       //当前目录不存在
        protocol::PDU pdu = protocol::PDU::default_respond(protocol::ENUM_MSG_TYPE_CREATE_DIR_RESPOND,DIR_NOT_EXIST);
        this->write((char*)&pdu,pdu.PDULen);
    }
}

void myTcpSocket::handleFlushFile(protocol::PDU *pdu)
{
    if(pdu == NULL) return;
    char* filePath = new char[pdu->uiMsgLen];  //用于存放文件路径
    memcpy(filePath,(char*)pdu->caMsg,pdu->uiMsgLen);//使用memcpy将协议中的文件路径拷出
    QDir fileDir(QString::fromUtf8(filePath,pdu->uiMsgLen-1));//创建QDir类对象
    QFileInfoList fileInfoList =  fileDir.entryInfoList(); //获取当前路径下所有文件列表
    protocol::FileInfo* fileList = (protocol::FileInfo*)malloc(sizeof(protocol::FileInfo)*fileInfoList.length());
    int j = 0;
    qDebug() << fileDir.current();
    qDebug() << fileInfoList.length();
    for(const QFileInfo& i : fileInfoList){   //面向范围的for 其中 i 为 集合fileInfoList 中的每一项 循环体中的语句为对每一个i进行
        if(i.isFile()){
//                qDebug() <<1;
                protocol::FileInfo fileInfo = protocol::createFileInfo(protocol::FILE_TYPE_FILE,i.fileName().toStdString().c_str(),i.size());
                fileList[j] = fileInfo;
                j++;
        }
        else if(i.isDir()){
//                qDebug() <<0;
                protocol::FileInfo fileInfo = protocol::createFileInfo(protocol::FILE_TYPE_DIR,i.fileName().toStdString().c_str(),i.size());
                fileList[j] = fileInfo;
                j++;
        }
    }
    protocol::FileInfoList* FinfoList = protocol::createFileInfoList(fileInfoList.length());  //创建文件信息列表对象
    memcpy((char*)FinfoList->FileList,(char*)fileList,sizeof(protocol::FileInfo)*fileInfoList.length());
    protocol::PDU* resultPdu = protocol::createPDU(FinfoList->structSize);  //创建协议对象
    resultPdu->uiMsgType = protocol::ENUM_MSG_TYPE_FLUSH_FILE_RESPOND; //修改协议的回复类型为刷新文件
    memcpy((char*)resultPdu->caMsg,(char*)FinfoList,FinfoList->structSize); //使用memcpy将FinfoList拷入协议
    this->write((char*)resultPdu,resultPdu->PDULen);
    qDebug()<<resultPdu->PDULen;
    qDebug()<<FinfoList->FileList[3].caFileName;
    free(resultPdu);
    resultPdu = nullptr;
    delete[] filePath;
    free(FinfoList);
    FinfoList = nullptr;
    free(fileList);
    fileList = nullptr;
//    qDebug() <<3;
}



//void myTcpSocket::handleGetFOnlineStatus(PDU *pdu)
//{
//    if(pdu == NULL) return;
//    char username[] = {"/n"};
//    memcpy(username,(char*)pdu->caData,64);

//}
