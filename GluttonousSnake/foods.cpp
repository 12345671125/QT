#include "foods.h"

foods::foods(QWidget *parent,int ParentX,int ParentY,int ParentW,int ParentH) : QObject(parent)
{

    this->timer = new QTimer(); //初始化定时器
    this->timer->setInterval(10000);//设置timer的触发时间为10秒

    this->timer->start(); //启动定时器

    this->PRect = QRectF(ParentX,ParentY,ParentW,ParentH); //获取父窗口位置大小信息

    this->init(); //初始化食物
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(timeOut())); //自定义类要使用connect需要继承QObject类或其子类
}
foods::~foods(){
    this->timer->stop();
    delete this->timer;
}

//food对象初始化
void foods::init(){
    this->img = QImage(":/img/foods.png");//载入食物图片
    this->size = 26;//设置大小
    this->isLive = true; //设置构造后为存活
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //使用当前时间生成种子
    double X = qrand() % ((int)this->PRect.width()-this->size-1) +1; //根据当前父窗口的宽度随机生成X值
    double Y = qrand() % ((int)this->PRect.height()-this->size-1) +1; //根据当前父窗口的高度随机生成Y值
    this->rect.setX(X);
    this->rect.setY(Y);
    this->rect.setWidth(this->size);
    this->rect.setHeight(this->size);
    qDebug()<<this->rect;
}

//编写timeOut槽函数
void foods::timeOut(){
    if(this->isLive == true){   //如果10秒后食物依旧存活，那么刷新其位置
        this->refresh();
    }
}

//刷新函数
void foods::refresh(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //使用当前时间生成种子
    double newX = qrand() % ((int)this->PRect.width()-this->size-1) +1; //根据当前父窗口的宽度随机生成X值
    double newY = qrand() % ((int)this->PRect.height()-this->size-1) +1;//根据当前父窗口的高度随机生成Y值
    this->rect.setX(newX);
    this->rect.setY(newY);
    this->rect.setWidth(this->size);
    this->rect.setHeight(this->size);
    qDebug()<<this->rect;
}

//监听父元素的位置大小改变
void foods::refreshPRect(int ParentX,int ParentY,int ParentW,int ParentH){
    this->PRect.setX(ParentX);
    this->PRect.setY(ParentY);
    this->PRect.setWidth(ParentW);
    this->PRect.setHeight(ParentH);
}
