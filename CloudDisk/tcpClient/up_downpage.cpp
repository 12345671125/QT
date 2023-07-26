#include "up_downpage.h"



up_downPage::up_downPage(QWidget *parent)
    : QWidget{parent}
{
    this->switchList = new QListWidget(this);
    this->switchList->addItem("上传文件");
    this->switchList->addItem("下载文件");
    this->upPage = new QListWidget(this);
    this->downPage = new QListWidget(this);
    this->stackedWidget = new QStackedWidget(this);
    this->stackedWidget->addWidget(this->upPage);
    this->stackedWidget->addWidget(this->downPage);
    this->switchList->setMaximumWidth(100);
    this->stackedWidget->setMinimumWidth(450);
    this->upPage->setMinimumWidth(this->stackedWidget->minimumWidth());
    upPage->setResizeMode(QListView::Adjust);
    upPage->setViewMode(QListView::IconMode);
    this->setWindowTitle("上传下载任务");
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(this->switchList);
    mainLayout->addWidget(this->stackedWidget);
    setLayout(mainLayout);
    QObject::connect(switchList,SIGNAL(currentRowChanged(int)),stackedWidget,SLOT(setCurrentIndex(int)));

}

up_downPage &up_downPage::getInstance()
{
    static up_downPage instance =  up_downPage();
    return instance;
}

void up_downPage::setPage(int index)
{
    this->switchList->setCurrentRow(index);
}

void up_downPage::createFileItem(QString FileName, qint64 FileSize)
{
    task* Task = new task(FileName,FileSize,this->upPage->width()-40,0,this);
    this->upPage->addItem(Task->getListWidgeItem());
    this->upPage->setItemWidget(Task->getListWidgeItem(),Task->getWidget());
    QThread* workThread = new QThread(this);
    Task->moveToThread(workThread);
    workThread->start();
    QObject::connect(this,SIGNAL(updateProgress(qint64)),Task,SLOT(updateProgress(qint64)));
}

void up_downPage::getuploadSize(qint64 uploadSize)
{
    emit updateProgress(uploadSize);
}

void up_downPage::switchPage()
{

}
