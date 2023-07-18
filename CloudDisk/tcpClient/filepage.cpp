#include "filepage.h"
#include "clientwin.h"
#include "QInputDialog"

FilePage::FilePage(QWidget *parent)
    : QWidget(parent)
{
    this->m_pFileListW = new QListWidget(this);
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
}

void FilePage::createDir()
{
    QString strNewDir = QInputDialog::getText(this,"新建文件夹","新建文件夹名字");
    if(!strNewDir.isEmpty()){
        if(strNewDir.length()>64){
            QMessageBox::warning(this,"新建文件夹","新文件夹名字不能超过64个字符!");
        }else{
            QString strName = clientWin::getInstance().getLoginName();
            QString strCurPath = clientWin::getInstance().curPath();
            qDebug()<<"curPath:"<<strCurPath;
            PDU* pdu = createPDU(strCurPath.length()+1);
            pdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_REQUEST;
            strncpy(pdu->caData,strName.toStdString().c_str(),strName.size());
            strncpy((char*)pdu->caMsg,strCurPath.toStdString().c_str(),strCurPath.size());
            memcpy(pdu->caData+64,strNewDir.toStdString().c_str(),strNewDir.size());
            clientWin::getInstance().getTcpSocket().write((char*)pdu,pdu->uiPDULen);
            free(pdu);
            pdu = nullptr;
        }

    }else{
        QMessageBox::warning(this,"新建文件夹","新文件夹名字不能为空！");
    }

}
