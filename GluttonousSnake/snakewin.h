#ifndef SNAKEWIN_H
#define SNAKEWIN_H

#include <QDialog>
#include <QVector>
#include <QImage>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

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
private:
    Ui::SnakeWin *ui;
    QVector<QRectF> snake; //蛇身的位置
    QRectF headRect;//储存蛇头的位置和大小（pos,size）
    QImage snaHead; //蛇头图片
    QImage snaBodyNode; //蛇身体图片
    int size = 32;//大小
    int speed = 32;
    QString dire; //移动方向
    QString Orientation; //头的朝向
    QRect frameRect;//图像区
    QTimer* timerPainter;//绘画定时器
    QTimer* timerPos;//位置定时器
    QPoint lastPos; //记录上次的位置
    void addBody(QRectF rect,int num = 1);//使蛇身边长
    void paintEvent(QPaintEvent *);//绘画事件
    void imgInit(void);
    void snakeInit(void);
    void move(int speed,QString dire);
    void keyPressEvent(QKeyEvent*); //键盘事件
    void changeOrientation();//改变方向
};
#endif // SNAKEWIN_H
