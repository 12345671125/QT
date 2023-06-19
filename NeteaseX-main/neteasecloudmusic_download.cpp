#include "neteasecloudmusic_download.h"
#include "ui_neteasecloudmusic_download.h"
#include <QProcess>
#include <QScreen>
#include <unistd.h>
int xuanze = 0;
int a = 0;
#include "form.h"

QProcess *myProcess = new QProcess();
QTimer *timer = new QTimer();

NeteaseCloudMusic_Download::NeteaseCloudMusic_Download(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NeteaseCloudMusic_Download)
{
    ui->setupUi(this);
}

NeteaseCloudMusic_Download::~NeteaseCloudMusic_Download()
{
    delete ui;
    delete myProcess;
    delete timer;
}

QString str3;

void NeteaseCloudMusic_Download::on_pushButton_clicked()
{
    system("rm 123.txt");
    system("rm 12345.txt");
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ofstream fout;
    QString str1,str2;
    fout.open(".netease.py", ios::out);
    str1=ui->textEdit->toPlainText();
    str2=ui->textEdit_2->toPlainText();
    str3=ui->textEdit_3->toPlainText();
    fout << "import requests" << endl;
    fout << "import os" << endl;
    fout << "import time" << endl;
    fout << "from bs4 import BeautifulSoup" << endl;
    fout << "header={" << endl;
    fout << "        'User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36'," << endl;
    fout << "        'Referer': 'https://music.163.com/'," << endl;
    fout << "}" << endl;
    fout << "an = os.path.exists(\"123.txt\")" << endl;
    fout << "ao = os.path.exists(\"12345.txt\")" << endl;
    fout << "if an == True:" << endl;
    fout << "    exit()" << endl;
    fout << "if ao == True:" << endl;
    fout << "    exit()" << endl;
    if(xuanze == 1)
    {
        fout << "link = \"http://music.163.com/" << str2.toStdString() << "?id=" << str1.toStdString() << "\"" << endl;
        fout << "r = requests.get(link, headers=header)" << endl;
        fout << "html = r.content" << endl;
        fout << "soup = BeautifulSoup(html, \"html.parser\")" << endl;
        fout << "songs = soup.find(\"ul\", class_=\"f-hide\").select(\"a\", limit=" << str3.toStdString() << ")" << endl;
        fout << "i=1" << endl;
        fout << "for s in songs:" << endl;
        fout << "    hello = open(\"123.txt\", \"a+\")" << endl;
        fout << "    song_id = s['href'][9:]" << endl;
        fout << "    song_name = s.text" << endl;
        fout << "    song_down_link = \"http://music.163.com/song/media/outer/url?id=\" + song_id + \".mp3\"" << endl;
        fout << "    hello.write(\"第 \" + str(i) + \" 首歌曲：\" + song_down_link)" << endl;
        fout << "    hello.write(\"正在下载...\")" << endl << endl;
        fout << "    response = requests.get(song_down_link, headers=header).content" << endl;
        fout << "    f = open(song_name + \".mp3\", 'wb')" << endl;
        fout << "    f.write(response)" << endl;
        fout << "    f.close()" << endl;
        fout << "    hello.write(\"下载完成.\\n\")" << endl;
        fout << "    i = i + 1" << endl;
        fout << "    hel = open(\"12345.txt\", \"w\")" << endl;
        fout << "    hel.write(str(i-1))" << endl;
        fout << "    hel.close()" << endl;
        fout << "    hello.close()" << endl;
        fout << "    time.sleep(0.2)" << endl;
        fout.close();
    }
    else if(xuanze == 2)
    {
        ui->textEdit_3->setPlainText("1");
        str3=ui->textEdit_3->toPlainText();
        fout << "song_name=" << "\"" << str2.toStdString() << "\"" << endl;
        fout << "song_id=" << "\"" << str1.toStdString() << "\"" << endl;
        fout << "song_down_link = \"http://music.163.com/song/media/outer/url?id=\" + song_id + \".mp3\"" << endl;
        fout << "hello = open(\"123.txt\", \"a+\")" << endl;
        fout << "hello.write(\"正在下载...\")" << endl << endl;
        fout << "response = requests.get(song_down_link, headers=header).content" << endl;
        fout << "f = open(song_name + \".mp3\", 'wb')" << endl;
        fout << "f.write(response)" << endl;
        fout << "f.close()" << endl;
        fout << "hello.write(\"下载完成.\\n\\r\")" << endl;
        fout << "hel = open(\"12345.txt\", \"w\")" << endl;
        fout << "hel.write(str(1))" << endl;
        fout << "hel.close()" << endl;
        fout << "hello.close()" << endl;
        fout.close();
    }
    else
    {
        ui->textEdit_4->insertPlainText("ERROR!!!");
        fout.close();
        return;
    }
    connect(timer, SIGNAL(timeout()), SLOT(on_pushButton_4_clicked()));
    timer->start(150);
    //QString netpath = QCoreApplication::applicationDirPath();
    //QString nets1 = "bash ";
    QString nets1 = "python3 .netease.py";
    //system("python .netease.py");
    //myProcess->start("python3 .netease.py");
    myProcess->start("bash");
    myProcess->write(QString(nets1+"\n").toUtf8());


}


void NeteaseCloudMusic_Download::on_radioButton_clicked()
{
    xuanze = 1;
}



void NeteaseCloudMusic_Download::on_pushButton_4_clicked()
{
    ifstream fin,fin2;
    fin.open("123.txt", ios::in);
    if (!fin.is_open())
        {
            ui->textEdit_4->insertPlainText("Failed to open 123.txt\n");
        }
    else{
            ui->textEdit_4->setPlainText("");
        }
    string str;
    //
    while (getline(fin, str))
        {
            ui->textEdit_4->insertPlainText(QString::fromStdString(str)+"\n");
        }
    fin.close();
    a++;
    fin2.open("12345.txt", ios::in);
    if(!fin2.is_open())
    {
        ui->textEdit_4->insertPlainText("Failed to open 12345.txt\n");
    }
    QString sttr;
    string stttr;
    getline(fin2, stttr);
    sttr = QString::fromStdString(stttr);
    fin2.close();
    if(str3.toInt() == sttr.toInt())
    {
        sleep(2);
        timer->stop();
        ui->textEdit_4->insertPlainText("Done!");
        myProcess->close();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}


void NeteaseCloudMusic_Download::on_radioButton_2_clicked()
{
    xuanze = 2;
}


void NeteaseCloudMusic_Download::on_pushButton_2_clicked()
{
    ui->textEdit->setPlainText("");
    ui->textEdit_2->setPlainText("");
    ui->textEdit_3->setPlainText("");
}


void NeteaseCloudMusic_Download::on_pushButton_3_clicked()
{
    ui->textEdit_4->setPlainText("");
}


void NeteaseCloudMusic_Download::on_pushButton_5_clicked()
{
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    int screenW = screenRect.width();
    int screenH = screenRect.height();
    Form *aboutwindow = new Form();
    aboutwindow->move(screenW/2, screenH/2);
    aboutwindow->show();
}

