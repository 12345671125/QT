#ifndef MYWIN_H
#define MYWIN_H

#include <QMainWindow>
#include <QSqlDatabase> //qt连接数据库类
#include <QSqlQuery> //qt数据库查询类
#include <QSqlQueryModel> //qt数据库查询类2
#include <QSqlError> //qt数据库错误类
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class myWin; }
QT_END_NAMESPACE

class myWin : public QMainWindow
{
    Q_OBJECT

public:
    myWin(QWidget *parent = nullptr);
    ~myWin();

private slots:
    void on_insertButton_clicked(); //插入槽函数

    void on_modifyButton_clicked(); //修改槽函数

    void on_deleteButton_clicked(); //删除槽函数

    void on_sortButton_clicked(); //删除槽函数

private:
    Ui::myWin *ui;
    QSqlDatabase db;//数据库连接对象
    QSqlQueryModel queryModel;//保存数据库查询结果对象
    void createDB(); //创建数据库
    void createTable();//创建数据表
    void queryTable(QString str = "");//执行查询操作
};
#endif // MYWIN_H
