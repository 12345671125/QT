#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class KeyBoard; }
QT_END_NAMESPACE

class KeyBoard : public QMainWindow
{
    Q_OBJECT

public:
    KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard();
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::KeyBoard *ui;

};
#endif // KEYBOARD_H
