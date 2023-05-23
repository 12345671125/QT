#ifndef OPEDB_H
#define OPEDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

class OpeDB : public QObject
{
    Q_OBJECT
public:
    explicit OpeDB(QObject *parent = nullptr);
    static OpeDB& getInsance();  //静态成员函数，单列模式创建数据库对象
    bool handleRegit(const char* name, const char* pwd);
    ~OpeDB();
signals:

public slots:

private:
    QSqlDatabase m_db; //数据库对象，用于连接数据库
    void init(); //用于数据库对象的初始化

};

#endif // OPEDB_H
