#include "fileinfopage.h"
#include "ui_fileinfopage.h"

FileInfoPage::FileInfoPage(QString FileName,QString FileSize,QString createdTime,QString location,QWidget *parent):
    QWidget(parent),
    ui(new Ui::FileInfoPage)
{
    ui->setupUi(this);
    this->FileName = FileName;
    this->FileSize = FileSize;
    this->createdTime = createdTime;
    this->location = location;
    this->ui->label->setText(FileName.append("的属性"));
    this->ui->listWidget->addItem("文件名 : " + this->FileName);
    this->ui->listWidget->addItem("文件大小 : " + this->FileSize);
    this->ui->listWidget->addItem("创建时间 : " + this->createdTime);
    this->ui->listWidget->addItem("文件路径 : " + this->location);
}

FileInfoPage::~FileInfoPage()
{
    delete ui;
}
