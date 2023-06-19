#include "mouse.h"
#include "ui_mouse.h"

Mouse::Mouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mouse)
{
    ui->setupUi(this);
    this->m_drag = false;
}

Mouse::~Mouse()
{
    delete ui;
}

void Mouse::mousePressEvent(QMouseEvent* event )
{
    qDebug()<<"mousePress";
    //是否为鼠标左键
    if(event->button() == Qt::LeftButton){
         QRect labelR = this->ui->label->frameRect();//获取label所在的位置
         labelR.translate(ui->label->pos());
         if(labelR.contains(event->pos())){
             qDebug()<<"contains";
             this->m_drag = true;
             this->m_pos = ui->label->pos() - event->pos();
             qDebug()<<this->m_pos;
         }
    }
}
void Mouse::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"mouseRelease";
    if(event->button() == Qt::LeftButton){
        this->m_drag = false;
    }
}
void Mouse::mouseMoveEvent(QMouseEvent* event)
{
    qDebug()<<"mouseMove";
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
