#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWin; }
QT_END_NAMESPACE

class ClientWin : public QMainWindow
{
    Q_OBJECT

public:
    ClientWin(QWidget *parent = nullptr);
    ~ClientWin();

private slots:
    //发送按钮槽函数
    void on_sendMsg_clicked();
    void onConnected(); //和服务器连接成功时执行的槽函数
    void onDisconnected();//和服务器断开连接槽函数
    void onReadyRead();//接收聊天消息的槽函数
    void onError();//网络执行异常的槽函数
    void on_pushButton_clicked();

private:
    Ui::ClientWin *ui;
    bool status; //标识状态：在线/离线
    QTcpSocket tcpSocket;//和服务器通行套接字
    QHostAddress serverIp; //服务器地址
    quint16 serverPost; //服务器端口
    QString localhostName; //主机名
    QString address; //获取本地id

};
#endif // CLIENTWIN_H
