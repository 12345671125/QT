#ifndef NETEASECLOUDMUSIC_DOWNLOAD_H
#define NETEASECLOUDMUSIC_DOWNLOAD_H

#include <QMainWindow>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include <QTimer>
#include<string>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class NeteaseCloudMusic_Download; }
QT_END_NAMESPACE

class NeteaseCloudMusic_Download : public QMainWindow
{
    Q_OBJECT

public:
    NeteaseCloudMusic_Download(QWidget *parent = nullptr);
    ~NeteaseCloudMusic_Download();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::NeteaseCloudMusic_Download *ui;
};
#endif // NETEASECLOUDMUSIC_DOWNLOAD_H
