#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class KeyBoard; }
QT_END_NAMESPACE

class KeyBoard : public QMainWindow
{
    Q_OBJECT

public:
    KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard();

private:
    Ui::KeyBoard *ui;
};
#endif // KEYBOARD_H
