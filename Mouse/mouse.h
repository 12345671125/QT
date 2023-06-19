#ifndef MOUSE_H
#define MOUSE_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QDebug>
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
    bool m_drag;
    QPoint m_pos;
    void mousePressEvent(QMouseEvent* );
    void mouseReleaseEvent(QMouseEvent* );
    void mouseMoveEvent(QMouseEvent* );
};
#endif // MOUSE_H
