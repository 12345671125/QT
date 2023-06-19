#include "keyboard.h"
#include "ui_keyboard.h"

KeyBoard::KeyBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
}

KeyBoard::~KeyBoard()
{
    delete ui;
}
void KeyBoard::keyPressEvent(QKeyEvent* event){
    qDebug()<<event->key();
    if(event->key() == 16777235 && this->ui->label->y()>0){
        this->ui->label->move(this->ui->label->x(),this->ui->label->y()-1);
    }
    if(event->key() == 16777237 && this->ui->label->y()<this->height()-this->ui->label->height()){
        this->ui->label->move(this->ui->label->x(),this->ui->label->y()+1);
    }
    if(event->key() == 16777236 && this->ui->label->x()<this->width()-this->ui->label->width()){
        this->ui->label->move(this->ui->label->x()+1,this->ui->label->y());
    }
    if(event->key() == 16777234 && this->ui->label->x()>0){
        this->ui->label->move(this->ui->label->x()-1,this->ui->label->y());
    }
}

