#ifndef MOUSE_H
#define MOUSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Mouse; }
QT_END_NAMESPACE

class Mouse : public QMainWindow
{
    Q_OBJECT

public:
    Mouse(QWidget *parent = nullptr);
    ~Mouse();

private:
    Ui::Mouse *ui;
};
#endif // MOUSE_H
