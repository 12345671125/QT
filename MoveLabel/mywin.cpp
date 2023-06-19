#include "mywin.h"
#include "ui_mywin.h"

myWin::myWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWin)
{
    ui->setupUi(this);
}

myWin::~myWin()
{
    delete ui;
}
void myWin::keyPressEvent(QKeyEvent* event){
//    qDebug()<<event->key();
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
void myWin::mousePressEvent(QMouseEvent* event )
{
//    qDebug()<<"mousePress";
    //是否为鼠标左键
    if(event->button() == Qt::LeftButton){
         QRect labelR = this->ui->label->frameRect();//获取label所在的位置
         labelR.translate(ui->label->pos());
         if(labelR.contains(event->pos())){
//             qDebug()<<"contains";
             this->m_drag = true;
             this->m_pos = ui->label->pos() - event->pos();
//             qDebug()<<this->m_pos;
         }
    }
}
void myWin::mouseReleaseEvent(QMouseEvent *event)
{
//    qDebug()<<"mouseRelease";
    if(event->button() == Qt::LeftButton){
        this->m_drag = false;
    }
}
void myWin::mouseMoveEvent(QMouseEvent* event)
{
//    qDebug()<<"mouseMove";
    if(this->m_drag == true){
        QPoint newPos = event->pos() + this->m_pos;
        QSize s1 = size(); //获取窗口的大小
        QSize s2 = this->ui->label->size();//获取label的大小
        int maxX = s1.width() - s2.width();
        int maxY = s1.height() - s2.height();
        if(newPos.x()<0){
            newPos.setX(0);
        }else if(newPos.x()>maxX){
            newPos.setX(maxX);
        }
        if(newPos.y()<0){
            newPos.setY(0);
        }else if(newPos.y()>maxY){
            newPos.setY(maxY);
        }
        this->ui->label->move(newPos);
    }
}
