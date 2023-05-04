#include "ernie.h"
#include "ui_ernie.h"

Ernie::Ernie(QWidget *parent)
    : QMainWindow(parent)//调用基类的构造函数，初始化基类
    , ui(new Ui::Ernie)
{
    ui->setupUi(this);
    this->imgIndex = 0;
    this->isStarted = false;
    qsrand(QTime::currentTime().msec());//根据当前时间生成随机数种子
    loadPhotos("./Screenshots/");
    qDebug()<<"加载图片个数："<<this->imgVector.size();
    QObject::connect(&this->timer,SIGNAL(timeout()),this,SLOT(timeOut()));
}

Ernie::~Ernie()
{
    delete ui;
}

//开始按钮对应的槽函数
void Ernie::on_pushButton_clicked()
{
    if(this->isStarted == false){
           this->isStarted = true;
//           this->imgTimer = startTimer(50);
            this->timer.start(50);
           this->ui->pushButton->setText("停止");
    }
    else{
            this->isStarted = false;
//            killTimer(this->imgTimer);
            this->timer.stop();
            this->ui->pushButton->setText("开始");
    }
}

void Ernie::loadPhotos(const QString& path)
{
    QDir imgDir(path);
    QStringList strList = imgDir.entryList(QDir::Files);
    if(strList.size()>0){
        for(int i = 0;i<strList.size();i++){
            QImage image(path+"/"+strList.at(i));
            this->imgVector.push_back(image);
        }
    }
    //递归遍历子目录中的图片
    QStringList strList1 = imgDir.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
    for(int i = 0;i<strList1.size();i++){
        this->loadPhotos(path+"/"+strList1.at(i));
    }

}//加载图片到容器

//void Ernie::timerEvent(QTimerEvent *)
//{
//    this->imgIndex = qrand() % this->imgVector.size();
//    update();
//}//重写定时器处理函数，在定时器到达时自动触发
void Ernie::timeOut(void){
    this->imgIndex = qrand() % this->imgVector.size();
    update();
}
void Ernie::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRect rect = ui->frame->frameRect();
    rect.translate(ui->frame->pos());
    painter.drawImage(rect,this->imgVector[this->imgIndex]);
}//重写绘图事件，在触发绘图时自动触发
