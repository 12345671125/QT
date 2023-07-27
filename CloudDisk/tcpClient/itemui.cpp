#include "itemui.h"
#include "opewidget.h"

ItemUI::ItemUI(QString FileName,int width,int height,QWidget *parent)
    : QWidget{parent}
{
    this->item =new QListWidgetItem();
    item->setSizeHint(QSize(width-20,40));
    this->itemWidget = new QWidget();
    this->progressBar =new QProgressBar();
    this->stopBtn =new QPushButton("停止");
    this->cancelBtn =new QPushButton("取消");
    QHBoxLayout* btnLayout =new QHBoxLayout();
    QVBoxLayout* mainVLayout = new QVBoxLayout();
    btnLayout->addWidget(stopBtn);
    btnLayout->addWidget(cancelBtn);
    QLabel* fileNameLab =new QLabel();
    fileNameLab->setText(FileName);
    QHBoxLayout* itemMainLay =new QHBoxLayout();
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

void ItemUI::createTask(QString absolutedPath, qintptr socketDesc)
{
    Task* task = new Task(NULL);
    QObject::connect(this,SIGNAL(taskStart()),task,SLOT(taskStart()));
    QObject::connect(this,SIGNAL(timeinit(QString,qintptr)),task,SLOT(timeinit(QString,qintptr)));
    QObject::connect(task,SIGNAL(updatePgBGUI(int)),this,SLOT(updatePgBGUI(int)));
    QObject::connect(task,SIGNAL(taskFin()),OpeWidget::getinstance().getfilePage(),SLOT(uploadFileEnd()));
    QThread* workThread = new QThread;
    task->moveToThread(workThread);
    emit timeinit(absolutedPath,socketDesc);
    workThread->start();
    emit taskStart();
}

void ItemUI::updatePgBGUI(int percent)
{
    this->progressBar->setValue(percent);
}

QListWidgetItem *ItemUI::getListWidgeItem()
{
    return this->item;
}
