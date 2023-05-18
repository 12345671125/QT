#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QFile> //文件类用于静态读取文件
#include <QMessageBox>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
namespace Ui { class clientWin; }
QT_END_NAMESPACE

class clientWin : public QMainWindow
{
    Q_OBJECT

public:
    clientWin(QWidget *parent = nullptr);

    ~clientWin();
public slots:
    void showConnected();
private:
    Ui::clientWin *ui;
    QString ip;//用于存放服务器ip
    qint16 port; //用于存放服务器端口
    QTcpSocket clientSocket;//客户端socket对象
    void initconfig(); //初始化服务器配置
    void connectToServer();
};
#endif // CLIENTWIN_H
