#include "mywin.h"
#include "ui_mywin.h"

myWin::myWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myWin)
{
    ui->setupUi(this);
    createDB();
    createTable();
    queryTable("SELECT * From studentInfo;");
}

myWin::~myWin()
{
    delete ui;
}

void myWin::createDB(){
    //添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名字(文件名)
    db.setDatabaseName("student.db");
    if(db.open()){
        qDebug()<<"创建/打开数据库成功";

    }else{
        qDebug()<<"创建/打开数据库失败!";
    }
}//创建数据库

void myWin::createTable(){
    QSqlQuery query;//如果无参创建，则为打开的默认数据库
    QString createTable = QString("Create Table studentInfo ("
                                  "id INT Primary key NOT NULL,"
                                  "name TEXT NOT NULL,"
                                  "score REAL NOT NULL);");
    if(query.exec(createTable)== false){
        qDebug() << createTable;
    }else{
        qDebug() << "创建数据表成功";
    }

}//创建数据表

void myWin::queryTable(QString str){
    QString query = QString(str);
    this->queryModel.setQuery(query);
    this->ui->tableView->setModel(&queryModel);

}//执行查询操作

//插入按钮槽函数
void myWin::on_insertButton_clicked()
{
    QSqlQuery sqlQuery;
    int id = ui->idInputBox->text().toInt();//获取用户输入的id
    QString name = ui->nameInputBox->text();//获取用户输入的姓名
    double score = ui->scoreInputBox->text().toDouble();//获取用户输入的分数
    QString query = QString("INSERT INTO studentInfo(id,name,score) values(%1,'%2',%3)")
            .arg(id).arg(name).arg(score);
    if(sqlQuery.exec(query) == false){
        qDebug() << query;
    }else{
        qDebug() << "插入成功!";
        queryTable("SELECT * From studentInfo;");
        this->ui->idInputBox->clear();
        this->ui->nameInputBox->clear();
        this->ui->scoreInputBox->clear();
    }

}
//修改按钮槽函数
void myWin::on_modifyButton_clicked()
{
    QSqlQuery sqlQuery;
    int id = ui->idInputBox->text().toInt();//获取用户输入的id
    QString name = ui->nameInputBox->text();//获取用户输入的姓名
    double score = ui->scoreInputBox->text().toDouble();//获取用户输入的分数
    QString query = QString("Update studentInfo set name = %2,score = %3 where id = %1")
            .arg(id).arg(name).arg(score);
    if(sqlQuery.exec(query) == false){
        qDebug() << query;
    }else{
        qDebug() << "修改成功!";
        queryTable("SELECT * From studentInfo;");
        this->ui->idInputBox->clear();
        this->ui->nameInputBox->clear();
        this->ui->scoreInputBox->clear();
    }

}
//删除按钮槽函数
void myWin::on_deleteButton_clicked()
{
    QSqlQuery sqlQuery;
    QString query = QString("Delete from studentInfo where id = %1;").arg(ui->idInputBox->text().toInt());
    sqlQuery.exec(query);
    queryTable("SELECT * From studentInfo;");
    if(sqlQuery.exec(query) == false){
        qDebug() << query;
    }else{
        qDebug() << "删除成功!";
        queryTable("SELECT * From studentInfo;");
        this->ui->idInputBox->clear();
    }
}
//排序按钮槽函数
void myWin::on_sortButton_clicked()
{
//    QSqlQuery sqlQuery; //生成sqlQuery查询对象
    QString selectBox1 = ui->selectBox1->currentText();
    QString selectBox2 = ui->selectBox2->currentText();
    if(selectBox2 == "升序")
        selectBox2 = "asc";
    else
        selectBox2 = "desc";
    QString query = QString("SELECT * from studentInfo Order by %1 %2;").arg(selectBox1).arg(selectBox2);
    this->queryTable(query);
}
