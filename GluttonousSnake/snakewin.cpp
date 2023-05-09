#include "snakewin.h"
#include "ui_snakewin.h"

SnakeWin::SnakeWin(QWidget *parent)     //初始化列表
    : QDialog(parent)
    , ui(new Ui::SnakeWin)
{
    //初始化ui
    ui->setupUi(this);

    //类内成员初始化
    this->headRect = QRectF(this->width()/2-32,this->height()/2-32,32,32);//保存蛇头的位置
    qDebug()<<this->headRect;
    this->timerPainter= new QTimer(); //初始化绘画定时器
    this->timerPos = new QTimer();  //初始化位置定时器
    this->timerFoever = new QTimer(); //初始化全局定时器
    this->dire = QString("Left");//初始化初始方向为向左
    this->imgInit();//初始化图片
    this->snakeInit();//初始化蛇
    this->controlOpt = "letterKey"; //初始化控制方式为字母键
    this->liveRect = QRectF(this->x(),this->y(),this->width(),this->height()-this->ui->lineEdit->height());//初始化存活区

    this->food = new foods(parent,this->liveRect.x(),this->liveRect.y(),this->liveRect.width(),this->liveRect.height());
    this->liveNumbers++;
    //信号连接槽函数
    QObject::connect(this->timerPainter,SIGNAL(timeout()),this,SLOT(timeOutPaint())); //连接定时器信号和自定义槽函数
    QObject::connect(this->timerPos,SIGNAL(timeout()),this,SLOT(timeOutPos())); //连接定时器信号和自定义槽函数
    QObject::connect(this->timerFoever,SIGNAL(timeout()),this,SLOT(timeOut())); //连接定时器信号和自定义槽函数

    //设置全局定时器
    timerFoever->setInterval(50); //设置定时器的触发间隔为0.1秒
    timerFoever->start();//开启定时器

    //设置绘画定时器
    timerPainter->setInterval(100); //设置定时器的触发间隔为0.1秒
    timerPainter->start();//开启定时器

    //设置移动定时器
    timerPos->setInterval(100);//设置定时器的触发间隔为0.1秒
    timerPos->start();//开启定时器
}

SnakeWin::~SnakeWin()
{
    delete ui;//释放ui类
    delete timerPainter;   //释放绘画定时器
    delete timerPos;   //释放位置定时器
    delete timerFoever; //释放全局定时器
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
//           qDebug()<<rect;
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

void SnakeWin::timeOut(){
    if(this->food == nullptr){
        createNFood(nullptr);
    }
    qDebug()<<this->food;

}
//画图事件
void SnakeWin::paintEvent(QPaintEvent*){
    QPainter painter(this);
//    painter.drawImage(this->headRect,this->snaHead);
    for(int i = 0;i<this->snake.size();i++){
        painter.drawImage(this->snake[i],this->snaBodyNode);
    }
    if(this->food != nullptr){
        painter.drawImage(this->food->rect,this->food->img);
    }


}

//重写窗口变化事件
void SnakeWin::resizeEvent(QResizeEvent *event){
//    qDebug()<<event->size().height()-this->ui->lineEdit->height();
    this->ui->lineEdit->resize(event->size().width(),this->ui->lineEdit->height()); //动态响应
    this->ui->lineEdit->pos().setX(0);
    this->ui->lineEdit->move(0,event->size().height()-this->ui->lineEdit->height());//动态响应
    this->liveRect = QRectF(this->x(),this->y(),this->width(),this->height()-this->ui->lineEdit->height());
    this->food->refreshPRect(this->liveRect.x(),this->liveRect.y(),this->liveRect.width(),this->liveRect.height());
//    qDebug()<<this->liveRect;
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
    capture();
    if(dire == "Left"){
        if(this->headRect.x()>0){
            QRectF node = QRectF(this->headRect.x()-this->size,this->headRect.y(),this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }else{
            QRectF node = QRectF(this->width()-this->size,this->headRect.y(),this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }

    }
    if(dire == "Right"){
        if(this->headRect.x()<this->width()){
            QRectF node = QRectF(this->headRect.x()+this->size,this->headRect.y(),this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }else{
            QRectF node = QRectF(0+this->size,this->headRect.y(),this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }

    }
    if(dire == "Up"){
        if(this->headRect.y()>0){
            QRectF node = QRectF(this->headRect.x(),this->headRect.y()-this->size,this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }else{
            QRectF node = QRectF(this->headRect.x(),this->liveRect.height()-this->size,this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }
    }
    if(dire == "Down"){
        if(this->headRect.y()<this->liveRect.height()){
            QRectF node = QRectF(this->headRect.x(),this->headRect.y()+this->size,this->size,this->size);
            this->snake.insert(0,node);
            this->headRect = node;
            this->snake.pop_back();
        }else{
                QRectF node = QRectF(this->headRect.x(),0+this->size,this->size,this->size);
                this->snake.insert(0,node);
                this->headRect = node;
                this->snake.pop_back();
              }
    }
}

//捕获食物
void SnakeWin::capture(){
//    qDebug()<<"头位置"<<this->headRect;
//    qDebug()<<"食物位置"<<this->food->rect;
    QPoint Point1(headRect.x(),headRect.y());
    QPoint Point2(headRect.x()+this->size,headRect.y()+this->size);
    QPoint Point3(this->food->rect.x(),this->food->rect.y());
    if(Point1.x()<=Point3.x() && Point3.x()<=Point2.x() && Point1.y() <= Point3.y() && Point3.y() <= Point2.y()){
           this->food->isLive = false;
            this->food->~foods();
            this->food = nullptr;
            this->liveNumbers--;
            qDebug()<<this->liveNumbers;
        QRectF rect = QRectF(this->snake.back().x(),this->snake.back().y(),this->snake.back().width()
                           ,this->snake.back().height());
            this->addBody(rect);
    }

}

//生成新的食物
void SnakeWin::createNFood(QWidget *parent){
    if(this->liveNumbers < 1){
        this->food = new foods(parent,this->liveRect.x(),this->liveRect.y(),this->liveRect.width(),this->liveRect.height());
        this->liveNumbers++;
        qDebug()<<this->liveNumbers;
        qDebug()<<food->rect;
    }
}
