#include "printer.h"
#include "ui_printer.h"

Printer::Printer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Printer)
{
    ui->setupUi(this);
    this->imgIndex = 1;
}

Printer::~Printer()
{
    delete ui;
}

//上一张按钮的槽函数
void Printer::on_prevBtn_clicked()
{
    if(this->imgIndex == 8)
           this->imgIndex = 0;
    this->imgIndex++;
    update();//触发绘图事件执行
}
//下一张按钮的槽函数
void Printer::on_nextBtn_clicked()
{
    if(this->imgIndex == 1)
           this->imgIndex = 9;
    this->imgIndex--;
    update();//触发绘图事件执行
}

void Printer::paintEvent(QPaintEvent *){     //绘图事件处理函数（虚函数）
//    qDebug("paintEvent");
    //1.创建画家对象
    QPainter painter(this);
    //2.获取绘图所在矩形区域
    QRect rect = ui->frame->frameRect();
//     qDebug() << "平移前" << rect;
    rect.translate(ui->frame->pos());//坐标值平移，让rect和printer使用相同坐标系
//    qDebug() << "平移前" << rect;
    //3.构建要绘制的图形对象
    QImage image(":/Screenshots/"+QString::number(this->imgIndex)+".png");//加冒号是因为图片在资源文件中而不是系统根目录
    //4.使用painter将image画到rect上
    painter.drawImage(rect,image);
}
