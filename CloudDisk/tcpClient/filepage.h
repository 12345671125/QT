#ifndef FILEPAGE_H
#define FILEPAGE_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "protocol.h"
#include <QMenu>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
#include "up_downpage.h"

class filePage : public QWidget
{
    Q_OBJECT
public:
    filePage(QWidget *parent = nullptr);
    void updateFileList(protocol::PDU* pdu);
    static filePage& getInstance();
    void emitSignal();


public slots:
    void createDir(); //创建文件夹
    void flushFile(); //刷新文件
    void goBack(); //返回
    void switchDir(QListWidgetItem * item); //切换路径
    void deleteDir();
    void deleteFile();
    void renameFile();
    void uploadFileEnd();

private:
    QListWidget* m_pFileListW;
    QPushButton* m_pReturnPB;
    QPushButton* m_pCreateDirPB;
    QPushButton* m_pDelDirPB;
    QPushButton* m_pRenameFilePB;
    QPushButton* m_pFlushFilePB;
    QPushButton* m_pUpLoadFilePB;
    QPushButton* m_pDownLoadPB;
    QPushButton* m_pDelFilePB;
    QPushButton* m_pShareFilePB;
    QString absolutedFilePath;
    QString uploadFileName;
    QFile* uploadfile;  //记录上传文件
    QString fileName;

signals:
    void createFileItem(QString absolutedFilePath,qintptr socketDesc);

private slots:
    void widgetListRequested(const QPoint &pos);
    void uploadFile();
};

#endif // FILEPAGE_H
