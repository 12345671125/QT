#include "mouse.h"
#include "ui_mouse.h"

Mouse::Mouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mouse)
{
    ui->setupUi(this);
}

Mouse::~Mouse()
{
    delete ui;
}

