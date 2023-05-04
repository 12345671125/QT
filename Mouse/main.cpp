#include "mouse.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mouse w;
    w.show();
    return a.exec();
}
