/*好友界面类*/


#ifndef FRIEND_H
#define FRIEND_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "online.h"
#include "protocol.h"

class Friend : public QWidget
{
    Q_OBJECT
public:
    explicit Friend(QWidget *parent = nullptr);
    void showAllOnlineUser(PDU* pdu);

signals:
public slots:
    void showOnline();
private:
    QTextEdit* m_pShowMsgTE;
    QListWidget* m_pFriendListWidget;
    QLineEdit* m_pInputMsgLE;
    QPushButton* m_pDelFriendPB;
    QPushButton* m_pFlushFriendPB;
    QPushButton* m_pShowOnlineUserPB;
    QPushButton* m_pSearchUserPB;
    QPushButton* m_pMsgSendPB;
    QPushButton* m_pPrivateChatPB;

    Online* online;
};

#endif // FRIEND_H
