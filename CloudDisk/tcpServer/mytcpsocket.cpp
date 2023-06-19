/*myTcpSocket类用于处理并响应客户端的请求*/

#include "mytcpsocket.h"
#include"mytcpserver.h"

myTcpSocket::myTcpSocket()
{
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    QObject::connect(this,SIGNAL(disconnected()),this,SLOT(clientOffine()));
}

QString myTcpSocket::getName()
{
    return this->m_strName;
}

void myTcpSocket::recvMsg()
{
    uint uiPDULen = 0;
    this->read((char*)&uiPDULen,sizeof(uint)); //para1:数据存放的地址，para2:读出的数据大小，读出uint字节的大小，这个uint为总的数据大小
    uint uiMsgLen = uiPDULen - sizeof(PDU); //用总的数据大小减去PDU结构体的默认，获取实际消息长度
    PDU* pdu = createPDU(uiMsgLen); //创建协议结构体，用于接收数据
    this->read((char*)pdu + sizeof (uint),uiPDULen-sizeof (uint)); /*让指针偏移来读取剩下的数据大小,先将pdu的指针类型转换为了char类型的指针，
那么当指针指针加一的时候会向后偏移一个字节的大小*/
    switch (pdu->uiMsgType)   //通过客户端传过来的协议中的消息类型来进行不同的处理
    {
        case ENUM_MSG_TYPE_REGIST_REQUEST:
        this->regist(pdu);  //处理注册
        break;

        case ENUM_MSG_TYPE_LOGIN_REQUEST:
        this->login(pdu); //处理登录
        break;

        case ENUM_MSG_TYPE_ALL_ONLINE_REQUEST:
        this->showOnline(pdu); //处理显示在线用户
        break;

        case ENUM_MSG_TYPE_SEARCHUSER_REQUEST:
        this->searchUser(pdu);
        break;


        case ENUM_MSG_TYPE_ADDFRIEND_REQUEST:
        this->addFriends(pdu);
        default: break;
    }
}

void myTcpSocket::regist(PDU* pdu)
{
    //    qDebug() << this->bytesAvailable(); //用 bytesAvailable 获取到客户端发送过来的字节数
        char password[64] = {"\n"};
        char username[64] = {"\n"};
        strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
        strncpy(password,pdu->caData+64,64);//从pdu.cadata中读取password
        bool ret = OpeDB::getInsance().handleRegit(username,password); //尝试将用户名密码写入数据库
        if(ret) //如果写入成功
        {
            PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_REGIST_RESPOND,REGIST_OK);
            qDebug() << pdu.caData;
            this->write((char*)&pdu,pdu.uiPDULen);
        }
        else   //如果写入失败
        {
            PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_REGIST_RESPOND,REGIST_FAILED);
            qDebug() << pdu.caData;
            this->write((char*)&pdu,pdu.uiPDULen);
        }
}

void myTcpSocket::clientOffine()
{
    OpeDB::getInsance().handleOffline(m_strName.toStdString().c_str()); //调用数据库方法
    emit offline(this); //发送offine信号
}

void myTcpSocket::login(PDU *pdu)
{
    char password[64] = {"\n"}; //创建password数组用于存放用户密码
    char username[64] = {"\n"}; //创建username数组用于存放用户名
    strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
    strncpy(password,pdu->caData+64,64);//从pdu.cadata中读取password
    bool ret = OpeDB::getInsance().handleLogin(username,password); //尝试登录
    if(ret) //如果登录成功
    {
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_LOGIN_RESPOND,LOGIN_OK); //通过默认回复模板产生pdu对象
        qDebug() << pdu.caData;
        this->write((char*)&pdu,pdu.uiPDULen);//将协议写入套接字
        this->m_strName = username;
    }
    else   //如果登录失败
    {
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_LOGIN_RESPOND,LOGIN_FAILED);//通过默认回复模板产生pdu对象
        qDebug() << pdu.caData;
        this->write((char*)&pdu,pdu.uiPDULen);//将协议写入套接字
    }

}

void myTcpSocket::showOnline(PDU* pdu)
{
    QStringList ret = OpeDB::getInsance().handleAllOnline(); //查询数据库获取在线用户信息，储存在字符串数组ret中
    uint uiMsgLen = ret.size()*32; //设置协议消息长度为在线用户长度
    PDU* respdu = createPDU(uiMsgLen);//生成传输协议对象，用来传输数据
    respdu->uiMsgType = ENUM_MSG_TYPE_ALL_ONLINE_RESPOND;//设置传输的消息类型
    for(int i = 0;i<ret.size();i++){ //使用循环将用户数据考入缓存区
        memcpy((char*)respdu->caMsg+i*32,ret.at(i).toStdString().c_str(),ret.at(i).size()); //每次向缓存区中拷入32个字节的内容并修改指针偏移量
    }
    write((char*)respdu,respdu->uiPDULen);//将协议内容写入套接字
    free(respdu); //释放缓存区
    respdu = NULL;//防止野指针
}

void myTcpSocket::searchUser(PDU *pdu)
{
    QStringList ret = OpeDB::getInsance().handleSearchUser(pdu->caData);
    uint uiMsgLen = ret.size()*32;
    qDebug()<<uiMsgLen;
    PDU* respdu = createPDU(uiMsgLen);
    respdu->uiMsgType = ENUM_MSG_TYPE_SEARCHUSER_RESPOND;
    for(int i = 0;i<ret.size();i++){
        memcpy((char*)respdu->caMsg+i*32,ret.at(i).toStdString().c_str(),ret.at(i).size());
    }
    write((char*)respdu,respdu->uiPDULen);
    free(respdu);
    respdu = NULL;
}

void myTcpSocket::addFriends(PDU *pdu)
{
    char pername[64] = {"\n"}; //创建password数组用于存放用户密码
    char username[64] = {"\n"}; //创建username数组用于存放用户名
    strncpy(username,pdu->caData,64);//从pdu.cadata中读取username
    strncpy(pername,pdu->caData+64,64);//从pdu.cadata中读取pername
    int ret = OpeDB::getInsance().handleAddFriend(pername,username);
    if(ret == -1){
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"unkown error");
        write((char*)&pdu,pdu.uiPDULen);
    }else if(ret == 0){
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"friend existed");
        write((char*)&pdu,pdu.uiPDULen);

    }else if(ret == 1){
        myTcpServer::getInstance().resend(pername,pdu);

    }else if(ret ==2){
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"user offine");
        write((char*)&pdu,pdu.uiPDULen);

    }else if(ret == 3){
        PDU pdu = PDU::default_respond(ENUM_MSG_TYPE_ADDFRIEND_RESPOND,"user not existed");
        write((char*)&pdu,pdu.uiPDULen);

    }


}
