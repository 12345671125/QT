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
    this->upPage->setSortingEnabled(true);
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

void up_downPage::createFileItem(QString curPath,QString absolutedPath)
{
    QString FileName = absolutedPath.mid(absolutedPath.lastIndexOf("/")+1,absolutedPath.length()-1);
    ItemUI* itemui = new ItemUI(FileName,this->upPage->width()-40,30,this);
    connect(itemui,SIGNAL(cancelTask(QListWidgetItem*)),this,SLOT(cancelTask(QListWidgetItem*)));
    connect(this,SIGNAL(createTask(QString,QString)),itemui,SLOT(createTask(QString,QString)));
    this->upPage->addItem(itemui->getListWidgetItem());
    this->upPage->setItemWidget(itemui->getListWidgetItem(),itemui->getWidget());
    emit createTask(curPath,absolutedPath);
    disconnect(this,SIGNAL(createTask(QString,QString)),itemui,SLOT(createTask(QString,QString)));
}

void up_downPage::cancelTask(QListWidgetItem* item)
{
    QModelIndex index  = this->upPage->indexFromItem(item);
//    qDebug()<<"cancelItemindex:"<<index.row();
//    qDebug()<<"count:"<<this->upPage->count();
    /*使剩下行上移*/
    this->upPage->takeItem(this->upPage->indexFromItem(item).row());
    if(this->upPage->count()-1 > index.row()){
        for(int i = index.row()+1;i<this->upPage->count();i++){
//            qDebug()<<"flag1";
            this->upPage->insertItem(i-1,this->upPage->item(i));
//            qDebug()<<"flag2";
            this->upPage->removeItemWidget(this->upPage->item(i));
        }

    }
    this->upPage->viewport()->update();
    this->upPage->update();

}

void up_downPage::switchPage()
{

}
