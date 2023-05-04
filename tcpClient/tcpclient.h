#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QWidget>
#include<QFile>
#include<QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class tcpClient; }
QT_END_NAMESPACE

class tcpClient : public QWidget
{
    Q_OBJECT

public:
    tcpClient(QWidget *parent = nullptr);
    ~tcpClient();
    void loadConfig();
    bool connectServer();

private:
    Ui::tcpClient *ui;
    QString m_strIP;
    quint16 m_usPort;
    QTcpSocket m_tcpSocket;//Qt的tcpsocket对象
public slots:
    void hasConnect();
};
#endif // TCPCLIENT_H
