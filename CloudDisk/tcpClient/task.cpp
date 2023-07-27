#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    /*ui初始化*/

}

Task::~Task()
{
    delete this->clientSocket;
    delete this->file;
}
void Task::uploadFileEnd()
{
    this->uploadTimer->stop();
    emit taskFin();
    qDebug()<<"Task::uploadFileEnd";
}
void Task::uploadFileData()
{
    if(!this->file->open(QIODevice::ReadOnly) && this->FileName.isEmpty()){
        QMessageBox::warning(NULL,"上传文件","打开文件失败");
        this->file = nullptr;
        return;
    }
    this->updataTimer->start();

}

void Task::taskStart()
{
    this->uploadFileData();
}
void Task::uploadData()
{
    char* pBuffer = new char[4096]; //数据缓冲区
    protocol::PDU* pdu = nullptr;
    qint64 ret = 0;
    memset(pBuffer,0,4096);
    ret = this->file->read(pBuffer,4096); //循环的中文件中读数据,一次读4096B
//    qDebug()<<ret;
    if(ret > 0 && ret <= 4096){
        pdu = protocol::createPDU(ret);
        pdu->uiMsgType = protocol::ENUM_MSG_TYPE_UPLOADBEG_FILE_REQUEST;
        memcpy(pdu->caData,this->FileName.toStdString().c_str(),this->FileName.length());
        memcpy((char*)pdu->caMsg,pBuffer,ret);
        this->clientSocket->write((char*)pdu,pdu->PDULen);
        this->curFileSize+=ret;
        emit updatePgBGUI(int(((double)curFileSize/totalFileSize) * 100));
    }else if(ret == 0)
    {
        this->updataTimer->stop();
        this->file->close();
        this->file = nullptr;
        this->uploadTimer->start();
    }
}

void Task::timeinit(QString absolutedPath,qintptr socket)
{
    /*成员数据初始化*/
    this->file = new QFile(absolutedPath,this);
    this->clientSocket = new QTcpSocket(this);
    this->uploadTimer = new QTimer(this);
    this->updataTimer = new QTimer(this);
    this->clientSocket->setSocketDescriptor(socket); //使用客户端的socketDecs来构造任务类的socket,使其单独与服务器通信;
    QString loFileName = absolutedPath.mid(absolutedPath.lastIndexOf("/")+1,absolutedPath.length()-1);
    this->FileName = loFileName.append('\0');
    this->totalFileSize = file->size();
    this->curFileSize = 0;
    this->uploadTimer->setInterval(1000);
    this->updataTimer->setInterval(50);
    this->curFileSize = 0;
    connect(updataTimer,SIGNAL(timeout()),this,SLOT(uploadData()));
    connect(uploadTimer,SIGNAL(timeout()),this,SLOT(uploadFileEnd()));
}
