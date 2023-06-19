#include "startpage.h"
#include "ui_startpage.h"
#include "snakewin.h"
#include "settingpage.h"

StartPage::StartPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
}

StartPage::~StartPage()
{
    delete ui;
}

void StartPage::on_pushButton_clicked()
{
    SnakeWin *snake = new SnakeWin(nullptr);
    snake->show();
    this->close();

}

void StartPage::on_pushButton_2_clicked()
{
    SettingPage * setting = new SettingPage;
    setting->show();
}
