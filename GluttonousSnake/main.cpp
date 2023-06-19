//#include "snakewin.h"
#include "startpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartPage page;
    page.show();
    return a.exec();
}
