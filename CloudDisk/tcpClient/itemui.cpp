#include "itemui.h"
#include "opewidget.h"
#include "clientwin.h"

ItemUI::ItemUI(QString FileName,int width,int height,QWidget *parent)
    : QWidget{parent}
{
    this->item =new QListWidgetItem();
    item->setSizeHint(QSize(width-20,40));
    this->itemWidget = new QWidget(this);
    this->progressBar =new QProgressBar(this);
    this->stopBtn =new QPushButton("停止",this);
    this->cancelBtn =new QPushButton("取消",this);
    this-> btnLayout =new QHBoxLayout();
    this-> mainVLayout = new QVBoxLayout();
    btnLayout->addWidget(stopBtn);
    btnLayout->addWidget(cancelBtn);
    this->fileNameLab =new QLabel(this);
    fileNameLab->setText(FileName);
    this->itemMainLay =new QHBoxLayout();
    this->progressBar->setTextVisible(true);
    itemMainLay->addWidget(fileNameLab);
    itemMainLay->addWidget(progressBar);
    itemMainLay->addLayout(btnLayout);
    mainVLayout->addLayout(itemMainLay);
    itemWidget->setLayout(mainVLayout);
}
QWidget *ItemUI::getWidget()
{
    return this->itemWidget;
}

void ItemUI::createTask(QString curPath,QString absolutedPath)
{
    qDebug()<<"main ThreadID:"<<QThread::currentThreadId();
    Task* task = new Task(NULL);
    QThread* workThread = new QThread(this);
    QObject::connect(this,SIGNAL(taskStart()),task,SLOT(taskStart()));
    QObject::connect(this,SIGNAL(taskThreadinit(QString,QString,QString,quint16)),task,SLOT(taskThreadinit(QString,QString,QString,quint16)));
    QObject::connect(task,SIGNAL(updatePgBGUI(int)),this,SLOT(updatePgBGUI(int)));
    QObject::connect(task,SIGNAL(taskFin()),OpeWidget::getinstance().getfilePage(),SLOT(uploadFileEnd()));
    QObject::connect(task,SIGNAL(finished()),workThread,SLOT(quit()));

//    QObject::connect(workThread,SIGNAL(finished()),task,SLOT(deleteLater()));
//    QObject::connect(workThread,SIGNAL(finished()),workThread,SLOT(deleteLater()));
    task->moveToThread(workThread);
    QString address = clientWin::getInstance().getServerIp();
    quint16 port = clientWin::getInstance().getServerPort();
    emit taskThreadinit(curPath,absolutedPath,address,port);
    workThread->start();
    emit taskStart();
    disconnect(this,SIGNAL(taskStart()),task,SLOT(taskStart()));
    disconnect(this,SIGNAL(taskThreadinit(QString,QString,QString,quint16)),task,SLOT(taskThreadinit(QString,QString,QString,quint16)));
//    disconnect(task,SIGNAL(taskFin()),OpeWidget::getinstance().getfilePage(),SLOT(uploadFileEnd()));
//    disconnect(task,SIGNAL(finished()),workThread,SLOT(quit()));
}

void ItemUI::updatePgBGUI(int percent)
{
    this->progressBar->setValue(percent);
}

QListWidgetItem *ItemUI::getListWidgeItem()
{
    return this->item;
}
