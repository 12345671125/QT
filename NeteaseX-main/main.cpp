#include "neteasecloudmusic_download.h"
#include <unistd.h>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "NeteaseX_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    NeteaseCloudMusic_Download w;

    pid_t mypid = getpid();
    printf("PID:%d\n",mypid);
    QScreen *scr = a.primaryScreen();
    int scr_w = scr->size().width();
    int scr_h = scr->size().height();
    w.move((scr_w - w.width()) / 2, (scr_h - w.height()) / 2);
    w.show();
    return a.exec();
}
