#include "snakewin.h"
#include "ui_snakewin.h"

SnakeWin::SnakeWin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SnakeWin)
{
    ui->setupUi(this);
    this->headRect = QRectF(this->width()/2-32,this->height()/2-32,32,32);//保存蛇头的位置
    qDebug()<<this->headRect;
    this->timerPainter= new QTimer(); //初始化绘画定时器
    this->timerPos = new QTimer();
    this->dire = QString("Left");//初始化初始方向为向左
    this->imgInit();//初始化图片
    this->snakeInit();//初始化蛇
    this->speed = 20;
    QObject::connect(this->timerPainter,SIGNAL(timeout()),this,SLOT(timeOutPaint())); //连接定时器信号和自定义槽函数
    QObject::connect(this->timerPos,SIGNAL(timeout()),this,SLOT(timeOutPos()));
    timerPainter->setInterval(50); //设置定时器的触发间隔为50微秒
    timerPainter->start();//开启定时器
    timerPos->setInterval(100);//设置定时器的触发间隔为1秒
    timerPos->start();//开启定时器
}

SnakeWin::~SnakeWin()
{
    delete ui;
}
//初始化载入图片
void SnakeWin::imgInit(void){
    this->snaBodyNode = QImage(":/img/body.png");
    this->snaHead = QImage(":/img/head.png");
}

//初始化蛇体
void SnakeWin::snakeInit(void){
    QRectF rect(this->headRect.x()+32,this->headRect.y(),this->size,this->size);
    addBody(rect);
    qDebug()<<rect;
    for(int i = 0;i<8;i++){
           rect.setX(rect.x()+32);
           rect.setY(rect.y());
           rect.setWidth(32);
           rect.setHeight(32);
           addBody(rect);
           qDebug()<<rect;
    }
}
//添加身体
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
    move(this->speed,this->dire);
}
//画图事件
void SnakeWin::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.drawImage(this->headRect,this->snaHead);
    for(int i = 0;i<this->snake.size();i++){
        painter.drawImage(this->snake[i],this->snaBodyNode);
    }

}
//键盘按下事件
void SnakeWin::keyPressEvent(QKeyEvent* event){
    qDebug()<<"keyPress";
//    if(event->key() == Qt::Key_Left){
//        this->dire = "Left";
//    }
//    if(event->key() == Qt::Key_Right){
//        this->dire = "Right";
//    }
//    if(event->key() == Qt::Key_Up){
//        this->dire = "Up";
//    }
//    if(event->key() == Qt::Key_Down){
//        this->dire = "Down";
//    }

    if(event->key() == Qt::Key_A){
        if(this->dire != "Left" && this->dire != "Right"){
            QMatrix matrix;
            matrix.rotate(90.0);
            this->snaHead = this->snaHead.transformed(matrix,Qt::FastTransformation);
            this->dire = "Left";
        }
    }
    if(event->key() == Qt::Key_D){
        if(this->dire != "Left" && this->dire != "Right"){
            QMatrix matrix;
            matrix.rotate(90.0);
            this->snaHead = this->snaHead.transformed(matrix,Qt::FastTransformation);
            this->dire = "Right";
        }
    }
    if(event->key() == Qt::Key_W){
        if(this->dire != "Up" && this->dire != "Down"){
            QMatrix matrix;
            matrix.rotate(90.0);
            this->snaHead = this->snaHead.transformed(matrix,Qt::FastTransformation);
            this->dire = "Up";
        }
    }
    if(event->key() == Qt::Key_S){
        if(this->dire != "Down" && this->dire != "Up"){
            QMatrix matrix;
            matrix.rotate(90.0);
            this->snaHead = this->snaHead.transformed(matrix,Qt::FastTransformation);
            this->dire = "Down";
        }
    }

}

//改变头朝向
//void SnakeWin::changeOrientation(){

//}

//移动
void SnakeWin::move(int speed,QString dire){
    if(QString::compare(dire,"Left") == 0){  //向左移动
        this->headRect.setX(this->headRect.x()-speed); //移动头
        this->headRect.setWidth(32);
        this->headRect.setHeight(32);
        if(this->snake.size()){
            this->snake[0].setX(this->headRect.x()+speed);
            this->snake[0].setY(this->headRect.y());
            this->snake[0].setWidth(32);
            this->snake[0].setHeight(32);
            for(int i = 1;i<this->snake.size();i++){ //移动身体
                this->snake[i].setX(this->snake[i-1].x());
                this->snake[i].setY(this->snake[i-1].y());
                this->snake[i].setWidth(32);
                this->snake[i].setHeight(32);
            }
        }

    }
    if(QString::compare(dire,"Right") == 0){  //向右移动
        this->headRect.setX(this->headRect.x()+speed); //移动头
        this->headRect.setWidth(32);
        this->headRect.setHeight(32);
        if(this->snake.size()){
            this->snake[0].setX(this->headRect.x()-speed);
            this->snake[0].setY(this->headRect.y());
            this->snake[0].setWidth(32);
            this->snake[0].setHeight(32);
            for(int i = 1;i<this->snake.size();i++){ //移动身体
                this->snake[i].setX(this->snake[i-1].x());
                this->snake[i].setY(this->snake[i-1].y());
                this->snake[i].setWidth(32);
                this->snake[i].setHeight(32);
            }
        }
    }
    if(QString::compare(dire,"Up") == 0){  //向上移动
        this->headRect.setY(this->headRect.y()-speed); //移动头
        this->headRect.setWidth(32);
        this->headRect.setHeight(32);
        if(this->snake.size()){
            this->snake[0].setX(this->headRect.x());
            this->snake[0].setY(this->headRect.y()+speed);
            this->snake[0].setWidth(32);
            this->snake[0].setHeight(32);
            for(int i = 1;i<this->snake.size();i++){ //移动身体
                this->snake[i].setX(this->snake[i-1].x());
                this->snake[i].setY(this->snake[i-1].y());
                this->snake[i].setWidth(32);
                this->snake[i].setHeight(32);
            }
        }
    }
    if(QString::compare(dire,"Down") == 0){  //向下移动
        this->headRect.setY(this->headRect.y()+speed); //移动头
        this->headRect.setWidth(32);
        this->headRect.setHeight(32);
        if(this->snake.size()){
            this->snake[0].setX(this->headRect.x());
            this->snake[0].setY(this->headRect.y()-speed);
            this->snake[0].setWidth(32);
            this->snake[0].setHeight(32);
            for(int i = 1;i<this->snake.size();i++){ //移动身体
                this->snake[i].setX(this->snake[i-1].x());
                this->snake[i].setY(this->snake[i-1].y());
                this->snake[i].setWidth(32);
                this->snake[i].setHeight(32);
            }
        }

    }
}
