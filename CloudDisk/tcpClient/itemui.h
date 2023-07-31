#ifndef ITEMUI_H
#define ITEMUI_H

#include <QWidget>
#include <QWidget>
#include <QDebug>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QListWidgetItem>
#include "task.h"

class ItemUI : public QWidget
{
    Q_OBJECT
public:
    explicit ItemUI(QString FileName,int width,int height,QWidget *parent = nullptr);
    ~ItemUI();
    QListWidgetItem* getListWidgetItem(); //用于返回item对象指针
    QWidget* getWidget(); //用于返回Widget对象指针

public slots:
    void createTask(QString curPath,QString absolutedPath); //创建上传下载任务槽函数
    void updatePgBGUI(int percent); //用于更新任务进度条
private:
    QWidget*itemWidget;
    QPushButton* cancelBtn;
    QPushButton* stopBtn;
    QLabel* fileNameLab;
    QProgressBar* progressBar;
    QListWidgetItem* item;
    QHBoxLayout* itemMainLay;
    QHBoxLayout* btnLayout;
    QVBoxLayout* mainVLayout;
    int curFileSize;
    QWaitCondition* WaitCondition;
private slots:
   void switchBtnText(void);  //用于切换按钮文本 开始-停止
   void cancelTask(void);  //用于取消任务
   void taskFin(void);
signals:
    void setItem(QListWidgetItem*,QWidget*);   //发往up_down页面用于将ui插入ListWidget
    void taskStart(void); //发送任务开始信号
    void taskThreadinit(QString,QString,QString,quint16,QWaitCondition*);//初始化任务对象信号
    void cancelTask(QListWidgetItem*); //发往up_down页面用于取消任务
};

#endif // ITEMUI_H
