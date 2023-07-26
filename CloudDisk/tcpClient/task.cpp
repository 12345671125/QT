#include "task.h"

task::task(QString FileName,qint64 FileSize,int width,int height,QWidget *parent)
    : QWidget{parent}
{
    this->FileName = FileName;
    this->totalFileSize = FileSize;
    this->item =new QListWidgetItem();
    //    qDebug()<<this->upPage->width();
    //    qDebug()<<this->upPage->height()/3;
    item->setSizeHint(QSize(width-20,40));
    this->itemWidget = new QWidget(this);
    this->progressBar =new QProgressBar(this);
    this->stopBtn =new QPushButton("停止",this);
    this->cancelBtn =new QPushButton("取消",this);
    QHBoxLayout* btnLayout =new QHBoxLayout();
    QVBoxLayout* mainVLayout = new QVBoxLayout();
    btnLayout->addWidget(stopBtn);
    btnLayout->addWidget(cancelBtn);
    QLabel* fileNameLab =new QLabel(this);
    fileNameLab->setText(FileName);
    QHBoxLayout* itemMainLay =new QHBoxLayout();
    this->progressBar->setTextVisible(true);
    itemMainLay->addWidget(fileNameLab);
    itemMainLay->addWidget(progressBar);
    itemMainLay->addLayout(btnLayout);
    mainVLayout->addLayout(itemMainLay);
    itemWidget->setLayout(mainVLayout);
    this->curFileSize = 0;
}

task::~task()
{
    delete this->item;
}

QWidget *task::getWidget()
{
    return this->itemWidget;
}

QListWidgetItem *task::getListWidgeItem()
{
    return this->item;
}

void task::updateProgress(qint64 uploadSize)
{
    this->curFileSize += uploadSize;
    qDebug()<<"this->curFileSize:"<<this->curFileSize;
    progressBar->setValue(int((((double)this->curFileSize)/this->totalFileSize)*100));
}
