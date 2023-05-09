#ifndef FOODS_H
#define FOODS_H
#include <QImage>
#include <QTimer>
#include <QTime>
#include <QDialog>
#include <QtGlobal> //使用随机数
#include <QDebug>
class foods :public QObject    //继承QObject类以使用connect
{
    Q_OBJECT
public:
    foods(QWidget *parent,int ParentX,int ParentY,int ParentW,int ParentH);
    QImage img; //存放食物图片
    QRectF rect; //用来存放food的位置和大小
    bool isLive; //是否存活
    void refreshPRect(int ParentX,int ParentY,int ParentW,int ParentH); //用来更新父窗口的变化

    ~foods();

public slots:
    void timeOut(); //定时器槽函数

private:
    QTimer* timer; //food食物定时器
    int size;
    QRectF PRect; //用来存放父窗口的位置和大小

    void refresh(); //当定时器触发并且当前food存活，用来刷新当前food的位置，防止吃不到
    void init(); //foods初始化
};

#endif // FOODS_H
