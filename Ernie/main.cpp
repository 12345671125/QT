#include "ernie.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ernie w;
    w.show();
    return a.exec();
}
