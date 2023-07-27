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
    QListWidgetItem* getListWidgeItem();
    QWidget* getWidget();

public slots:
    void createTask(QString absolutedPath,qintptr socketDesc);
    void updatePgBGUI(int percent);
private:
    QWidget*itemWidget;
    QPushButton* cancelBtn;
    QPushButton* stopBtn;
    QLabel* fileNameLab;
    QProgressBar* progressBar;
    QListWidgetItem* item;
signals:
    void setItem(QListWidgetItem*,QWidget*);
    void taskStart(void);
    void timeinit(QString,qintptr);
};

#endif // ITEMUI_H
