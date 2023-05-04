#ifndef ERNIE_H
#define ERNIE_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QDir>
#include <QTime>
#include <QVector>
#include <QImage>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Ernie; }
QT_END_NAMESPACE

class Ernie : public QMainWindow
{
    Q_OBJECT

public:
    Ernie(QWidget *parent = nullptr);
    QVector<QImage> imgVector;
    int imgIndex;
    int imgTimer;//定时器id
    bool isStarted;
    QTimer timer;
    void loadPhotos(const QString& path);//加载图片到容器
    /*void timerEvent(QTimerEvent *);*///重写定时器处理函数，在定时器到达时自动触发
    void paintEvent(QPaintEvent *);//重写绘图事件，在触发绘图时自动触发
    ~Ernie();
private slots:
    void on_pushButton_clicked();
    void timeOut(void);

private:
    Ui::Ernie *ui;
};
#endif // ERNIE_H
