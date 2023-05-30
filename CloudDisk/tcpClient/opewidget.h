#ifndef OPEWIDGET_H
#define OPEWIDGET_H

#include <QWidget>
#include <QListWidget>
#include "friend.h"
#include <QStackedWidget>

class OpeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OpeWidget(QWidget *parent = nullptr);

signals:

private:
    QListWidget *m_pListW;
    Friend* m_pFriend;
    QStackedWidget *m_pSW;
};

#endif // OPEWIDGET_H
