#include "snakewin.h"
#include "ui_snakewin.h"

SnakeWin::SnakeWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SnakeWin)
{
    //初始化ui
    ui->setupUi(this);

    //类内成员初始化
    this->headRect = QRectF(this->width()/2-32,this->height()/2-32,32,32);//保存蛇头的位置
    qDebug()<<this->headRect;
    this->timerPainter= new QTimer(); //初始化绘画定时器
    this->timerPos = new QTimer();
    this->dire = QString("Left");//初始化初始方向为向左
    this->imgInit();//初始化图片
    this->snakeInit();//初始化蛇
    this->controlOpt = "letterKey"; //初始化控制方式为字母键

    //信号连接槽函数
    QObject::connect(this->timerPainter,SIGNAL(timeout()),this,SLOT(timeOutPaint())); //连接定时器信号和自定义槽函数
    QObject::connect(this->timerPos,SIGNAL(timeout()),this,SLOT(timeOutPos()));

    //设置绘画定时器
    timerPainter->setInterval(100); //设置定时器的触发间隔为0.1秒
    timerPainter->start();//开启定时器

    //设置移动定时器
    timerPos->setInterval(100);//设置定时器的触发间隔为0.1秒
    timerPos->start();//开启定时器
}

SnakeWin::~SnakeWin()
{
    delete ui;
}

//初始化载入图片
void SnakeWin::imgInit(void){
    this->snaBodyNode = QImage(":/img/body.png");
}

//初始化蛇体
void SnakeWin::snakeInit(void){
    QRectF rect(this->headRect.x(),this->headRect.y(),this->size,this->size);
    for(int i = 0;i<3;i++){
           addBody(rect);
           rect.setX(rect.x());
           rect.setY(rect.y());
           rect.setWidth(32);
           rect.setHeight(32);
           qDebug()<<rect;
    }
}
//变长
void SnakeWin::addBody(QRectF rect,int num){
    if(num>0){
        for(int i = num;i>0;i--){
            this->snake.push_back(rect);
        }
    }else{
        qDebug()<<"addBodyFault!";
    }
}
//画图定时器槽函数
void SnakeWin::timeOutPaint(){
    update();
//    qDebug()<<"update";
}
//移动蛇定时器槽函数
void SnakeWin::timeOutPos(void){
//    qDebug()<< dire;
    move(this->dire);
}
//画图事件
void SnakeWin::paintEvent(QPaintEvent*){
    QPainter painter(this);
//    painter.drawImage(this->headRect,this->snaHead);
    for(int i = 0;i<this->snake.size();i++){
        painter.drawImage(this->snake[i],this->snaBodyNode);
    }

}

//键盘按下事件
void SnakeWin::keyPressEvent(QKeyEvent* event){

//    qDebug()<<"keyPress";

    //使用WASD键控制
    if(this->controlOpt == "letterKey"){
        if(event->key() == Qt::Key_A){                //监听A键
            if(this->dire != "Left" && this->dire != "Right"){
                this->dire = "Left";
            }
        }
        if(event->key() == Qt::Key_D){              //监听D键
            if(this->dire != "Left" && this->dire != "Right"){
                this->dire = "Right";
            }
        }
        if(event->key() == Qt::Key_W){              //监听W键
            if(this->dire != "Up" && this->dire != "Down"){
                this->dire = "Up";
            }
        }
        if(event->key() == Qt::Key_S){              //监听S键
            if(this->dire != "Down" && this->dire != "Up"){
                this->dire = "Down";
            }
        }
    }


    //使用方向键控制
    if(this->controlOpt == "direKey"){
        if(event->key() == Qt::Key_Left){                //监听左键
            if(this->dire != "Left" && this->dire != "Right"){
                this->dire = "Left";
            }
        }
        if(event->key() == Qt::Key_Right){              //监听右键
            if(this->dire != "Left" && this->dire != "Right"){
                this->dire = "Right";
            }
        }
        if(event->key() == Qt::Key_Up){              //监听上键
            if(this->dire != "Up" && this->dire != "Down"){
                this->dire = "Up";
            }
        }
        if(event->key() == Qt::Key_Down){              //监听下键
            if(this->dire != "Down" && this->dire != "Up"){
                this->dire = "Down";
            }
        }
    }

}

//移动
void SnakeWin::move(QString dire){
    if(dire == "Left"){
            QRectF node = QRectF(this->headRect.x()-this->size,this->headRect.y(),this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
    }
    if(dire == "Right"){
            QRectF node = QRectF(this->headRect.x()+this->size,this->headRect.y(),this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
    }
    if(dire == "Up"){
            QRectF node = QRectF(this->headRect.x(),this->headRect.y()-this->size,this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
    }
    if(dire == "Down"){
            QRectF node = QRectF(this->headRect.x(),this->headRect.y()+this->size,this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
    }
}
