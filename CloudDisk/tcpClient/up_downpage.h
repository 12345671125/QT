#ifndef UP_DOWNPAGE_H
#define UP_DOWNPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <QListWidget>
#include <QDebug>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include "task.h"
#include <QThread>


class up_downPage : public QWidget
{
    Q_OBJECT
public:
    explicit up_downPage(QWidget *parent = nullptr);
    static up_downPage& getInstance();
    void setPage(int index);
public slots:
    void createFileItem(QString FileName,qint64 FileSize);
    void getuploadSize(qint64 uploadSize);
private:
    QStackedWidget* stackedWidget;
    QListWidget* upPage;
    QListWidget* downPage;
    QListWidget* switchList;


signals:
   void updateProgress(qint64 uploadSize);

private slots:
    void switchPage();

};

#endif // UP_DOWNPAGE_H
