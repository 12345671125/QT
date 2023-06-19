#ifndef MYWIN_H
#define MYWIN_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
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
    bool m_drag;
    QPoint m_pos;
    void mousePressEvent(QMouseEvent* );
    void mouseReleaseEvent(QMouseEvent* );
    void mouseMoveEvent(QMouseEvent* );
    void keyPressEvent(QKeyEvent* event);
};
#endif // MYWIN_H
