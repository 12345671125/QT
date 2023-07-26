#ifndef TASK_H
#define TASK_H

#include "process.h"
#include <QWidget>
#include <QDebug>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QLayout>
#include <QListWidgetItem>

class task : public QWidget
{
    Q_OBJECT
public:
    explicit task(QString FileName,qint64 FileSize,int width,int height = 0,QWidget *parent = NULL);
    ~task();
    QWidget* getWidget();
    QListWidgetItem* getListWidgeItem();

public slots:
    void updateProgress(qint64 uploadSize);
private:
    QWidget*itemWidget;
    QPushButton* cancelBtn;
    QPushButton* stopBtn;
    QLabel* fileNameLab;
    QProgressBar* progressBar;
    QListWidgetItem* item;
    QString FileName;
    qint64 totalFileSize;
    qint64 curFileSize;
signals:

};

#endif // TASK_H
