#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    /*ui初始化*/
    this->absolutedPath = QString();
    this->absolutedPath.clear();

}

Task::~Task()
{
    qDebug()<<QThread::currentThreadId()<<"~Task";
    delete this->clientSocket;
    delete this->file;
    delete this->updataTimer;
    delete this->uploadTimer;
    QThread::currentThread()->quit();
//    QThread::currentThread()->wait();
}
void Task::uploadFileEnd()
{
    this->uploadTimer->stop();
    emit taskFin();
    qDebug()<<QThread::currentThreadId()<<"emit finished";
    emit finished();
    this->~Task();

//    qDebug()<<"Task::uploadFileEnd";
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

void Task::taskThreadinit(QString curPath,QString absolutedPath,QString address,quint16 port)
{
    if(!this->absolutedPath.isEmpty()){
        return;
    }
    this->absolutedPath = this->absolutedPath;
    /*成员数据初始化*/
    this->file = new QFile(absolutedPath,this);
    this->clientSocket = new QTcpSocket(this);
    this->uploadTimer = new QTimer(this);
    this->updataTimer = new QTimer(this);
    this->clientSocket->connectToHost(QHostAddress(address),port); //使用客户端的socketDecs来构造任务类的socket,使其单独与服务器通信;
    QString loFileName = absolutedPath.mid(absolutedPath.lastIndexOf("/")+1,absolutedPath.length()-1);
//    qDebug()<< absolutedPath;
    this->FileName = loFileName.append('\0');
    this->totalFileSize = file->size();
    this->curFileSize = 0;
    this->uploadTimer->setInterval(100);
    this->updataTimer->setInterval(1);
    this->curFileSize = 0;
    uploadFile(curPath,absolutedPath);
}

void Task::uploadFile(QString curPath,QString absolutedfileName)
{
    QFile file = QFile(absolutedfileName);
    file.open(QFile::ReadOnly);
    qDebug()<<file.size();
    QString loFileName = absolutedfileName.mid(absolutedfileName.lastIndexOf("/")+1,absolutedfileName.length()-1);
    loFileName = loFileName.append('\0');
    qDebug()<<loFileName;
    QString curpath = curPath;
    curPath.append('\0');
    protocol::FileInfo *fileInfo = protocol::createFileInfo(protocol::FILE_TYPE_FILE,loFileName.toStdString().c_str(),
                                                            file.size(),curpath.length());
    memcpy(fileInfo->savaPath,curPath.toStdString().c_str(),curPath.length());
    protocol::PDU* pdu = protocol::createPDU(fileInfo->totalSize);
    pdu->uiMsgType = protocol::ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST;
    memcpy((char*)pdu->caMsg,(char*)fileInfo,fileInfo->totalSize);
    this->clientSocket->write((char*)pdu,pdu->PDULen);
    free(pdu);
    pdu = nullptr;
    connect(updataTimer,SIGNAL(timeout()),this,SLOT(uploadData()));
    connect(uploadTimer,SIGNAL(timeout()),this,SLOT(uploadFileEnd()));
}
