#ifndef SERVERWIN_H
#define SERVERWIN_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class serverWin; }
QT_END_NAMESPACE

class serverWin : public QMainWindow
{
    Q_OBJECT

public:
    serverWin(QWidget *parent = nullptr);
    ~serverWin();

private slots:
    //创建服务器按钮的槽函数
    void on_createButton_clicked();
    //响应客户端连接请求的槽函数
    void onNewConnection();
    //接收客户端消息的槽函数
    void onReadyRead();
    //将聊天消息转发
    void sendMessage(const QByteArray& buf);
    void timeOut();
private:
    Ui::serverWin *ui;
    QTcpServer tcpServer;
    quint16 port;//服务器端口
    QHostAddress address; //服务器监听地址
    QTcpSocket listenSocket; //监听socket 用来接受监听
    QList<QTcpSocket*> tcpClientList; //用来存放已连接socket描述字
    QTimer* timer;//定时器
//    QTcpSocket client;
};
#endif // SERVERWIN_H
