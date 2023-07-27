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

void up_downPage::createFileItem(QString absolutedPath,qintptr socketDesc)
{
    QString FileName = absolutedPath.mid(absolutedPath.lastIndexOf("/")+1,absolutedPath.length()-1);
    ItemUI* itemui = new ItemUI(FileName,this->upPage->width()-40,30,this);
    connect(this,SIGNAL(createTask(QString,qintptr)),itemui,SLOT(createTask(QString,qintptr)));
    this->upPage->addItem(itemui->getListWidgeItem());
    this->upPage->setItemWidget(itemui->getListWidgeItem(),itemui->getWidget());
    emit createTask(absolutedPath,socketDesc);
}

void up_downPage::switchPage()
{

}
