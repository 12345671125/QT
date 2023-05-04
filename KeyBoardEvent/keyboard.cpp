#include "keyboard.h"
#include "ui_keyboard.h"

KeyBoard::KeyBoard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
}

KeyBoard::~KeyBoard()
{
    delete ui;
}

