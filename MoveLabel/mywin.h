#ifndef MYWIN_H
#define MYWIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class myWin; }
QT_END_NAMESPACE

class myWin : public QMainWindow
{
    Q_OBJECT

public:
    myWin(QWidget *parent = nullptr);
    ~myWin();

private:
    Ui::myWin *ui;
};
#endif // MYWIN_H
