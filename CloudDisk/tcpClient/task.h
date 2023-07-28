#ifndef TASK_H
#define TASK_H
#pragma once
#include <QObject>
#include "protocol.h"
#include <QMessageBox>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>
#include <QThread>
#include <QHostAddress>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = NULL);
    ~Task();
    void uploadFileData();

public slots:
    void taskStart(void);
    void uploadData();
    void uploadFileEnd();
    void taskThreadinit(QString curPath,QString absolutedPath, QString address, quint16 port);
    void uploadFile(QString curPath,QString absolutedFileName);
private:

    QString FileName; //文件名
    qint64 totalFileSize; //文件大小
    qint64 curFileSize; //已上传文件大小
    QTcpSocket* clientSocket; //存放客户端socket
    QFile* file;  //文件描述符
    QTimer* updataTimer = nullptr; //用于间隔时间发送数据
    QTimer* uploadTimer = nullptr;
    QString absolutedPath;
signals:
    void updatePgBGUI(int percent);
    void taskFin();
    void finished();

};

#endif // TASK_H
