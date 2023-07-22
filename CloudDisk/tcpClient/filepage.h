#ifndef FILEPAGE_H
#define FILEPAGE_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "protocol.h"

class filePage : public QWidget
{
    Q_OBJECT
public:
    filePage(QWidget *parent = nullptr);
    void updateFileList(protocol::PDU* pdu);
    static filePage& getInstance();


public slots:
    void createDir(); //创建文件夹
    void flushFile(); //刷新文件
    void goBack(); //返回
    void switchDir(QListWidgetItem * item); //切换路径

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

};

#endif // FILEPAGE_H
