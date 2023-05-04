#ifndef PRINTER_H
#define PRINTER_H
#include <QMainWindow>
#include <QPainter>//画家类
#include <QImage>//图片类
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class Printer; }
QT_END_NAMESPACE

class Printer : public QMainWindow
{
    Q_OBJECT

public:
    Printer(QWidget *parent = nullptr);
    ~Printer();

private slots:
    void on_prevBtn_clicked();//上一张对应的槽函数

    void on_nextBtn_clicked();//下一张对应的槽函数

private:

    void paintEvent(QPaintEvent *);//绘图事件处理函数（基类中的虚函数）
    Ui::Printer *ui;
    int imgIndex; //图片索引
};
#endif // PRINTER_H
