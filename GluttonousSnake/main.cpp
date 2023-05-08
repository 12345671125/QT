#include "snakewin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SnakeWin w;
    w.show();
    return a.exec();
}
