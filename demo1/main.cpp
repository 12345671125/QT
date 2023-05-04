#include "widget.h"//Qt中的一个类对应一个头文件，类名对应头文件名
#include <QPushButton>
#include <QLabel>
#include <QApplication>//qt系统提供的标准声明头文件
//类的声明与行为的实现分开在.h 和.cpp中
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);//QtApp主程序，必须
    QLabel label("我是一个标签");
    QPushButton button("我是一个按钮");
    button.show();
    label.show();
    return app.exec();//返回事件循环，必须
}
