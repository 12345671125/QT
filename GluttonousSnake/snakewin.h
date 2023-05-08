#ifndef SNAKEWIN_H
#define SNAKEWIN_H

#include <QDialog>    //Dialog父类
#include <QVector>     //向量
#include <QImage>       //图片类
#include <QPainter>     //画家类
#include <QDebug>       //控制台输出
#include <QTimer>       //计时器类
#include <QKeyEvent>    //键盘事件类

QT_BEGIN_NAMESPACE
namespace Ui { class SnakeWin; }
QT_END_NAMESPACE

class SnakeWin : public QDialog
{
    Q_OBJECT

public:
    SnakeWin(QWidget *parent = nullptr);
    ~SnakeWin();
public slots:
     void timeOutPaint(void);//绘画计时器函数
     void timeOutPos(void);//蛇位置计时器函数
//     void timeOut(void); //全局控制
private:
    Ui::SnakeWin *ui;
    QVector<QRectF> snake; //蛇身的位置
    QRectF headRect;    //储存蛇头的位置和大小（pos,size）
    QImage snaBodyNode;     //蛇身体图片
    int size = 32;  //大小
    QString dire; //移动方向
    QString Orientation; //头的朝向
    QString controlOpt;//控制选项

    QTimer* timerPainter;   //绘画定时器
    QTimer* timerPos;   //位置定时器
    QTimer* timeFoever; //全局定时器，游戏进行时启动

    void addBody(QRectF rect,int num = 1);  //使蛇身边长
    void paintEvent(QPaintEvent *); //绘画事件
    void imgInit(void); //初始化蛇图片
    void snakeInit(void); //初始化蛇
    void move(QString dire); //控制蛇的移动
    void keyPressEvent(QKeyEvent*); //键盘按下事件
};
#endif // SNAKEWIN_H
