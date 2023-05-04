#include "mywin.h"
#include "ui_mywin.h"

myWin::myWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWin)
{
    ui->setupUi(this);
}

myWin::~myWin()
{
    delete ui;
}

