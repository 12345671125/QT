#include "filepage.h"
#include "clientwin.h"
#include "QInputDialog"
filePage::filePage(QWidget *parent)
    : QWidget(parent)
{
    this->m_pFileListW = new QListWidget;
    this->m_pReturnPB = new QPushButton("返回",this);
    this->m_pCreateDirPB = new QPushButton("创建文件夹",this);
    this->m_pDelDirPB = new QPushButton("删除文件夹",this);
    this->m_pRenameFilePB = new QPushButton("文件重命名",this);
    this->m_pFlushFilePB = new QPushButton("刷新文件",this);

    QVBoxLayout* pDirVBL = new QVBoxLayout;
    pDirVBL->addWidget(m_pReturnPB);
    pDirVBL->addWidget(m_pCreateDirPB);
    pDirVBL->addWidget(m_pDelDirPB);
    pDirVBL->addWidget(m_pRenameFilePB);
    pDirVBL->addWidget(m_pFlushFilePB);

    this->m_pUpLoadFilePB =  new QPushButton("上传文件",this);
    this->m_pDownLoadPB = new QPushButton("下载文件",this);
    this->m_pDelFilePB = new QPushButton("删除文件",this);
    this->m_pShareFilePB = new QPushButton("分享文件",this);

    QVBoxLayout* pFileVBL = new QVBoxLayout;
    pFileVBL->addWidget(this->m_pUpLoadFilePB);
    pFileVBL->addWidget(this->m_pDownLoadPB);
    pFileVBL->addWidget(this->m_pDelFilePB);
    pFileVBL->addWidget(this->m_pShareFilePB);

    QHBoxLayout* pMain = new QHBoxLayout;
    pMain->addWidget(m_pFileListW);
    pMain->addLayout(pDirVBL);
    pMain->addLayout(pFileVBL);

    setLayout(pMain);

    connect(m_pCreateDirPB,SIGNAL(clicked(bool)),this,SLOT(createDir()));
    connect(m_pFlushFilePB,SIGNAL(clicked(bool)),this,SLOT(flushFile()));
    connect(m_pReturnPB,SIGNAL(clicked(bool)),this,SLOT(goBack()));
    connect(m_pFileListW,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(switchDir(QListWidgetItem*)));
}

void filePage::updateFileList(protocol::PDU *pdu)
{
    OpeWidget::getinstance().getfilePage()->m_pFileListW->clear();
    if(pdu  == NULL) return;
    uint FileLsitLenth = pdu->uiMsgLen/sizeof(protocol::FileInfo);
    protocol::FileInfo* FileList = (protocol::FileInfo*)malloc(sizeof(protocol::FileInfo) * FileLsitLenth);
    memcpy((char*)FileList,(char*)pdu->caMsg,pdu->uiMsgLen);
    for(uint i = 2; i<FileLsitLenth ; i++){   //去除. ..
        QListWidgetItem *pItem = new QListWidgetItem();
        if(FileList[i].iFileType == protocol::FILE_TYPE_DIR)
        {
            qDebug()<<FileList[i].caFileName;
            pItem->setIcon(QIcon(QPixmap(":/img/FileDir.jpg")));
            pItem->setWhatsThis("DIR");
        }
        else if(FileList[i].iFileType == protocol::FILE_TYPE_FILE)
        {
            qDebug()<<FileList[i].caFileName;
            pItem->setIcon(QIcon(QPixmap(":/img/FILE.jpg")));
            pItem->setWhatsThis("FILE");
        }
        pItem->setText(FileList[i].caFileName);
        OpeWidget::getinstance().getfilePage()->m_pFileListW->addItem(pItem);

    }

}

filePage &filePage::getInstance()
{
   static filePage filepage;
    return filepage;
}

void filePage::createDir()
{
    QString strNewDir = QInputDialog::getText(this,"新建文件夹","新建文件夹名字");
    if(!strNewDir.isEmpty()){
        if(strNewDir.length()>64){
            QMessageBox::warning(this,"新建文件夹","新文件夹名字不能超过64个字符!");
        }else{
            QString strName = clientWin::getInstance().getLoginName();
            QString strCurPath = clientWin::getInstance().curPath();
            qDebug()<<"curPath:"<<strCurPath;
            protocol::PDU* pdu = protocol::createPDU(strCurPath.length()+1);
            pdu->uiMsgType = protocol::ENUM_MSG_TYPE_CREATE_DIR_REQUEST;
            strncpy(pdu->caData,strName.toStdString().c_str(),strName.size());
            strncpy((char*)pdu->caMsg,strCurPath.toStdString().c_str(),strCurPath.size());
            memcpy(pdu->caData+64,strNewDir.toStdString().c_str(),strNewDir.size());
            clientWin::getInstance().getTcpSocket().write((char*)pdu,pdu->PDULen);
            free(pdu);
            pdu = nullptr;
        }

    }else{
        QMessageBox::warning(this,"新建文件夹","新文件夹名字不能为空！");
    }

}

void filePage::flushFile()
{
    QString CurPath = clientWin::getInstance().curPath();
    protocol::PDU* pdu = protocol::createPDU(CurPath.size() + 1);
    pdu->uiMsgType = protocol::ENUM_MSG_TYPE_FLUSH_FILE_REQUEST;
    memcpy((char*)pdu->caMsg,CurPath.toStdString().c_str(),CurPath.size());
    clientWin::getInstance().getTcpSocket().write((char*)pdu,pdu->PDULen);
    free(pdu);
    pdu = nullptr;
}

void filePage::goBack()
{
    QString CurPath = clientWin::getInstance().curPath();
    qDebug()<<clientWin::getInstance().curPath();
    if(CurPath == ("./"+clientWin::getInstance().getLoginName()))
    {
        QMessageBox::information(this,"切换目录","到底啦!");
    }
    else
    {
        CurPath = CurPath.mid(0,CurPath.lastIndexOf("/"));
        protocol::PDU* pdu = protocol::createPDU(CurPath.size() + 1);
        pdu->uiMsgType = protocol::ENUM_MSG_TYPE_FLUSH_FILE_REQUEST;
        memcpy((char*)pdu->caMsg,CurPath.toStdString().c_str(),CurPath.size());
        clientWin::getInstance().getTcpSocket().write((char*)pdu,pdu->PDULen);
        free(pdu);
        pdu = nullptr;
        clientWin::getInstance().modifyCurPath(CurPath);
    }

}

void filePage::switchDir(QListWidgetItem * item)
{
    if(item->whatsThis() == "DIR"){
        QString CurPath = clientWin::getInstance().curPath();
        CurPath.append("/").append(item->text());
        protocol::PDU* pdu = protocol::createPDU(CurPath.size() + 1);
        pdu->uiMsgType = protocol::ENUM_MSG_TYPE_FLUSH_FILE_REQUEST;
        memcpy((char*)pdu->caMsg,CurPath.toStdString().c_str(),CurPath.size());
        clientWin::getInstance().getTcpSocket().write((char*)pdu,pdu->PDULen);
        free(pdu);
        pdu = nullptr;
        clientWin::getInstance().modifyCurPath(CurPath);
        qDebug()<<clientWin::getInstance().curPath();
    }
    if(item->whatsThis() == "FILE");
}
