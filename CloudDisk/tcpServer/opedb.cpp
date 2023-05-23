#include "opedb.h"

OpeDB::OpeDB(QObject *parent) : QObject(parent)
{
    this->m_db = QSqlDatabase::addDatabase("QSQLITE");
    this->init();
}

OpeDB& OpeDB::getInsance()
{
    static OpeDB instance;
    return instance;
}

bool OpeDB::handleRegit(const char *name, const char *pwd)
{
    if(name == nullptr || pwd == nullptr ){   //当name 或 pwd 为NULL时
        return false;
    }
    QString sqlString = QString("insert into userInfo(name,pwd) values('%1','%2')").arg(name).arg(pwd);
    qDebug()<<sqlString;
    QSqlQuery query;
    return query.exec(sqlString);

}

OpeDB::~OpeDB()
{
    this->m_db.close();
}

void OpeDB::init()
{
    this->m_db.setHostName("localhost");//添加数据库用户名
    this->m_db.setDatabaseName("D:\\CODE\\code\\2023\\QT\\CloudDisk\\tcpServer\\cloud.db"); //添加对应数据库名
    if(this->m_db.open()){  //调用open方法打开数据库
        QSqlQuery query;//创建数据库查询对象
        query.exec("select * from userInfo");//数据库查询对象执行对应sql语句
        while(query.next()){
            QString data = QString("%1,%2,%3").arg(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
            qDebug() << data;
        }
    }else{
        QMessageBox::critical(NULL,"打开数据库","打开数据库失败");
    }
}
