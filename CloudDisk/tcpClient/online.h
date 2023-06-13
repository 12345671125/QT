/*在线页面类*/

#ifndef ONLINE_H
#define ONLINE_H

#include <QWidget>
#include "protocol.h"
#include "clientwin.h"

namespace Ui {
class Online;
}

class Online : public QWidget
{
    Q_OBJECT

public:
    explicit Online(QWidget *parent = nullptr);
    ~Online();
    void showUser(PDU* pdu);
    void showSearchUser(PDU* pdu);

private slots:
    void on_addFriendButton_clicked();

private:
    Ui::Online *ui;
};

#endif // ONLINE_H
