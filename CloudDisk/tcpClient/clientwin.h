#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QTcpSocket>
#include <QDebug>
#include <QFile> //文件类用于静态读取文件
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class clientWin; }
QT_END_NAMESPACE

class clientWin : public QMainWindow
{
    Q_OBJECT

public:
    clientWin(QWidget *parent = nullptr);
    void initconfig();
    ~clientWin();

private:
    Ui::clientWin *ui;
    QString ip;//用于存放服务器ip
    qint16 port; //用于存放服务器端口
};
#endif // CLIENTWIN_H
