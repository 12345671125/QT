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
    timerFoever->setInterval(100); //设置定时器的触发间隔为0.1秒
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
    update();  //触发绘画事件
//    qDebug()<<"update";
}

//移动蛇定时器槽函数
void SnakeWin::timeOutPos(void){
//    qDebug()<< dire;
    move(this->dire); //触发移动事件
}

//全局定时器
void SnakeWin::timeOut(){
    if(this->food == nullptr){          //防御性编程
        createNFood(nullptr);
    }
    this->gameOver();

}
//画图事件
void SnakeWin::paintEvent(QPaintEvent*){
    QPainter painter(this); //创建画家对象
//    painter.drawImage(this->headRect,this->snaHead);
    for(int i = 0;i<this->snake.size();i++){                 //循环绘制蛇身
        painter.drawImage(this->snake[i],this->snaBodyNode);
    }
    if(this->food != nullptr){                       //防御性编程
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

//移动->采取每次添加头结点，删除尾结点的方式来达到移动效果
void SnakeWin::move(QString dire){
    capture();
    if(dire == "Left"){
        if(this->headRect.x()>0){     //实现穿墙
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
        if(this->headRect.x()<this->width()){ //实现穿墙
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
        if(this->headRect.y()>0){ //实现穿墙
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
        if(this->headRect.y()<this->liveRect.height()){ //实现穿墙
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
    QPoint pointHead = QPoint(this->headRect.x()+this->size/2,this->headRect.y()+this->size/2); //获取蛇头的中心位置
    QPoint pointFood = QPoint(this->food->rect.x()+this->food->size/2,this->food->rect.y()+this->food->size/2);//获取食物的中心位置
    int distance =  sqrt(pow((pointFood.x()-pointHead.x()),2)+pow((pointFood.y()-pointHead.y()),2)); //计算两点之间的距离
    if(distance < (this->size +this->food->size)){   //如果两点之间的距离小于两者的半径和
           this->food->isLive = false; //将食物的是否存活标为false
            this->food->~foods();   //显式调用food的析构函数，摧毁food
            this->food = nullptr; //防御性编程，将food成员标为null防止野指针
            this->liveNumbers--; //将存活的food的数量减一
//            qDebug()<<this->liveNumbers;
        QRectF rect = QRectF(this->snake.back().x(),this->snake.back().y(),this->snake.back().width()
                           ,this->snake.back().height());
            this->addBody(rect);  //添加身体
    }

}

//生成新的食物
void SnakeWin::createNFood(QWidget *parent){
    if(this->liveNumbers < 1){   //防御性编程，如果存活的食物数量<1
        this->food = new foods(parent,this->liveRect.x(),this->liveRect.y(),this->liveRect.width(),this->liveRect.height());//生成新的食物对象
        this->liveNumbers++;
//        qDebug()<<this->liveNumbers;
        qDebug()<<food->rect;
    }
}
void SnakeWin::gameOver(){
    qDebug()<<"head"<<this->snake.front();
    qDebug()<<"rail"<<this->snake.back();
    if(this->snake.front().x() == this->snake.back().x() &&
            this->snake.front().y() == this->snake.back().y() && this->snake.size()>1){  //如果头的坐标==尾的坐标，游戏结束
        this->timerPainter->stop();
        this->timerPos->stop();
        this->timerFoever->stop();
        QMessageBox msgBox;
        msgBox.setText("GAME OVER!");
        msgBox.exec();
        if (msgBox.clickedButton())
            {
                this->close();
            }
    }
}
