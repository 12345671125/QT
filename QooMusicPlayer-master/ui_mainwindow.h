/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <lyricstreamwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *logo_button;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *search_edit;
    QPushButton *search_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *menu_button;
    QPushButton *SyncButton;
    QPushButton *LogoutButton;
    QPushButton *min_button;
    QPushButton *normal_button;
    QPushButton *max_button;
    QPushButton *close_button;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *play_list_button;
    QPushButton *local_music_button;
    QPushButton *my_favorite_button;
    QPushButton *recommond_music_button;
    QPushButton *my_song_list_button;
    QListWidget *MusiclistWidget;
    QPushButton *add_list_Button;
    QStackedWidget *stackedWidget;
    QWidget *searchResultPage;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *searchResultTable;
    QWidget *Musicpage;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *MusicTable;
    QWidget *localMusicpage;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *localMusicTable;
    QWidget *Favoritepage;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *FavoriteMusicTable;
    QWidget *playListpage;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *PlayListTable;
    QWidget *Userpage;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *AvatarLabel;
    QVBoxLayout *verticalLayout_11;
    QLabel *UsernameLabel;
    QSpacerItem *horizontalSpacer_4;
    QTabWidget *tabWidget;
    QWidget *lyricsPage;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *scrollArea;
    LyricStreamWidget *lyricWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *playingCoverLablel;
    QVBoxLayout *verticalLayout_4;
    QLabel *playingNameLabel;
    QLabel *playingArtistLabel;
    QPushButton *back_button;
    QPushButton *play_button;
    QPushButton *forward_button;
    QLabel *now_duration;
    QSlider *playProgressSlider;
    QLabel *all_duration;
    QPushButton *lyric_button;
    QPushButton *sound_button;
    QPushButton *mode_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/logo"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 11, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        logo_button = new QPushButton(centralwidget);
        logo_button->setObjectName(QString::fromUtf8("logo_button"));
        logo_button->setMinimumSize(QSize(180, 0));
        logo_button->setMaximumSize(QSize(180, 16777215));
        logo_button->setFocusPolicy(Qt::NoFocus);
        logo_button->setStyleSheet(QString::fromUtf8(""));
        logo_button->setIcon(icon);
        logo_button->setFlat(true);

        horizontalLayout->addWidget(logo_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border-radius:5px;\n"
"	background-color: rgb(221, 221, 221);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(11, 5, 11, 5);
        search_edit = new QLineEdit(widget_3);
        search_edit->setObjectName(QString::fromUtf8("search_edit"));
        search_edit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:transparent;\n"
"border:none;\n"
"}"));

        horizontalLayout_2->addWidget(search_edit);

        search_button = new QPushButton(widget_3);
        search_button->setObjectName(QString::fromUtf8("search_button"));
        search_button->setFocusPolicy(Qt::NoFocus);
        search_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/search"), QSize(), QIcon::Normal, QIcon::Off);
        search_button->setIcon(icon1);
        search_button->setFlat(true);

        horizontalLayout_2->addWidget(search_button);


        horizontalLayout->addWidget(widget_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        menu_button = new QPushButton(centralwidget);
        menu_button->setObjectName(QString::fromUtf8("menu_button"));
        menu_button->setFocusPolicy(Qt::NoFocus);
        menu_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/menu"), QSize(), QIcon::Normal, QIcon::Off);
        menu_button->setIcon(icon2);
        menu_button->setFlat(true);

        horizontalLayout->addWidget(menu_button);

        SyncButton = new QPushButton(centralwidget);
        SyncButton->setObjectName(QString::fromUtf8("SyncButton"));
        SyncButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/sync"), QSize(), QIcon::Normal, QIcon::Off);
        SyncButton->setIcon(icon3);
        SyncButton->setFlat(true);

        horizontalLayout->addWidget(SyncButton);

        LogoutButton = new QPushButton(centralwidget);
        LogoutButton->setObjectName(QString::fromUtf8("LogoutButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/logout"), QSize(), QIcon::Normal, QIcon::Off);
        LogoutButton->setIcon(icon4);
        LogoutButton->setFlat(true);

        horizontalLayout->addWidget(LogoutButton);

        min_button = new QPushButton(centralwidget);
        min_button->setObjectName(QString::fromUtf8("min_button"));
        min_button->setFocusPolicy(Qt::NoFocus);
        min_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/min"), QSize(), QIcon::Normal, QIcon::Off);
        min_button->setIcon(icon5);
        min_button->setFlat(true);

        horizontalLayout->addWidget(min_button);

        normal_button = new QPushButton(centralwidget);
        normal_button->setObjectName(QString::fromUtf8("normal_button"));
        normal_button->setFocusPolicy(Qt::NoFocus);
        normal_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/min2"), QSize(), QIcon::Normal, QIcon::Off);
        normal_button->setIcon(icon6);
        normal_button->setFlat(true);

        horizontalLayout->addWidget(normal_button);

        max_button = new QPushButton(centralwidget);
        max_button->setObjectName(QString::fromUtf8("max_button"));
        max_button->setFocusPolicy(Qt::NoFocus);
        max_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/max"), QSize(), QIcon::Normal, QIcon::Off);
        max_button->setIcon(icon7);
        max_button->setFlat(true);

        horizontalLayout->addWidget(max_button);

        close_button = new QPushButton(centralwidget);
        close_button->setObjectName(QString::fromUtf8("close_button"));
        close_button->setFocusPolicy(Qt::NoFocus);
        close_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/close"), QSize(), QIcon::Normal, QIcon::Off);
        close_button->setIcon(icon8);
        close_button->setFlat(true);

        horizontalLayout->addWidget(close_button);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        play_list_button = new QPushButton(centralwidget);
        play_list_button->setObjectName(QString::fromUtf8("play_list_button"));
        play_list_button->setMaximumSize(QSize(180, 16777215));
        play_list_button->setFocusPolicy(Qt::NoFocus);
        play_list_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/songs"), QSize(), QIcon::Normal, QIcon::Off);
        play_list_button->setIcon(icon9);
        play_list_button->setFlat(true);

        verticalLayout_2->addWidget(play_list_button);

        local_music_button = new QPushButton(centralwidget);
        local_music_button->setObjectName(QString::fromUtf8("local_music_button"));
        local_music_button->setMaximumSize(QSize(180, 16777215));
        local_music_button->setFocusPolicy(Qt::NoFocus);
        local_music_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/local"), QSize(), QIcon::Normal, QIcon::Off);
        local_music_button->setIcon(icon10);
        local_music_button->setFlat(true);

        verticalLayout_2->addWidget(local_music_button);

        my_favorite_button = new QPushButton(centralwidget);
        my_favorite_button->setObjectName(QString::fromUtf8("my_favorite_button"));
        my_favorite_button->setMaximumSize(QSize(180, 16777215));
        my_favorite_button->setFocusPolicy(Qt::NoFocus);
        my_favorite_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/like"), QSize(), QIcon::Normal, QIcon::Off);
        my_favorite_button->setIcon(icon11);
        my_favorite_button->setFlat(true);

        verticalLayout_2->addWidget(my_favorite_button);

        recommond_music_button = new QPushButton(centralwidget);
        recommond_music_button->setObjectName(QString::fromUtf8("recommond_music_button"));
        recommond_music_button->setMaximumSize(QSize(180, 16777215));
        recommond_music_button->setFocusPolicy(Qt::NoFocus);
        recommond_music_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/recommond"), QSize(), QIcon::Normal, QIcon::Off);
        recommond_music_button->setIcon(icon12);
        recommond_music_button->setFlat(true);

        verticalLayout_2->addWidget(recommond_music_button);

        my_song_list_button = new QPushButton(centralwidget);
        my_song_list_button->setObjectName(QString::fromUtf8("my_song_list_button"));
        my_song_list_button->setMaximumSize(QSize(180, 16777215));
        my_song_list_button->setFocusPolicy(Qt::NoFocus);
        my_song_list_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icon/songslist"), QSize(), QIcon::Normal, QIcon::Off);
        my_song_list_button->setIcon(icon13);
        my_song_list_button->setFlat(true);

        verticalLayout_2->addWidget(my_song_list_button);

        MusiclistWidget = new QListWidget(centralwidget);
        MusiclistWidget->setObjectName(QString::fromUtf8("MusiclistWidget"));
        MusiclistWidget->setMaximumSize(QSize(180, 16777215));
        MusiclistWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        MusiclistWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"background-color:transparent;\n"
"border:none;\n"
"}"));
        MusiclistWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_2->addWidget(MusiclistWidget);

        add_list_Button = new QPushButton(centralwidget);
        add_list_Button->setObjectName(QString::fromUtf8("add_list_Button"));
        add_list_Button->setMaximumSize(QSize(180, 16777215));
        add_list_Button->setFocusPolicy(Qt::NoFocus);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icon/add"), QSize(), QIcon::Normal, QIcon::Off);
        add_list_Button->setIcon(icon14);
        add_list_Button->setFlat(true);

        verticalLayout_2->addWidget(add_list_Button);


        horizontalLayout_3->addLayout(verticalLayout_2);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}"));
        searchResultPage = new QWidget();
        searchResultPage->setObjectName(QString::fromUtf8("searchResultPage"));
        searchResultPage->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}\n"
"QTableCornerButton::section{\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(searchResultPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        searchResultTable = new QTableWidget(searchResultPage);
        searchResultTable->setObjectName(QString::fromUtf8("searchResultTable"));
        searchResultTable->setFocusPolicy(Qt::NoFocus);
        searchResultTable->setContextMenuPolicy(Qt::CustomContextMenu);
        searchResultTable->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"	alternate-background-color: rgba(132, 136, 139, 20);\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section\n"
"{\n"
"	background:transparent;\n"
"}"));
        searchResultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        searchResultTable->setAlternatingRowColors(true);
        searchResultTable->setShowGrid(false);

        verticalLayout_3->addWidget(searchResultTable);

        stackedWidget->addWidget(searchResultPage);
        Musicpage = new QWidget();
        Musicpage->setObjectName(QString::fromUtf8("Musicpage"));
        Musicpage->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}\n"
"QTableCornerButton::section{\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(Musicpage);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        MusicTable = new QTableWidget(Musicpage);
        MusicTable->setObjectName(QString::fromUtf8("MusicTable"));
        MusicTable->setFocusPolicy(Qt::NoFocus);
        MusicTable->setContextMenuPolicy(Qt::CustomContextMenu);
        MusicTable->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"	alternate-background-color: rgba(132, 136, 139, 20);\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section\n"
"{\n"
"	background:transparent;\n"
"}"));
        MusicTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        MusicTable->setAlternatingRowColors(true);
        MusicTable->setShowGrid(false);

        verticalLayout_9->addWidget(MusicTable);

        stackedWidget->addWidget(Musicpage);
        localMusicpage = new QWidget();
        localMusicpage->setObjectName(QString::fromUtf8("localMusicpage"));
        localMusicpage->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}\n"
"QTableCornerButton::section{\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(localMusicpage);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        localMusicTable = new QTableWidget(localMusicpage);
        localMusicTable->setObjectName(QString::fromUtf8("localMusicTable"));
        localMusicTable->setFocusPolicy(Qt::NoFocus);
        localMusicTable->setContextMenuPolicy(Qt::CustomContextMenu);
        localMusicTable->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"	alternate-background-color: rgba(132, 136, 139, 20);\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section\n"
"{\n"
"	background:transparent;\n"
"}"));
        localMusicTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        localMusicTable->setAlternatingRowColors(true);
        localMusicTable->setShowGrid(false);

        verticalLayout_5->addWidget(localMusicTable);

        stackedWidget->addWidget(localMusicpage);
        Favoritepage = new QWidget();
        Favoritepage->setObjectName(QString::fromUtf8("Favoritepage"));
        Favoritepage->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}\n"
"QTableCornerButton::section{\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(Favoritepage);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        FavoriteMusicTable = new QTableWidget(Favoritepage);
        FavoriteMusicTable->setObjectName(QString::fromUtf8("FavoriteMusicTable"));
        FavoriteMusicTable->setFocusPolicy(Qt::NoFocus);
        FavoriteMusicTable->setContextMenuPolicy(Qt::CustomContextMenu);
        FavoriteMusicTable->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"	alternate-background-color: rgba(132, 136, 139, 20);\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section\n"
"{\n"
"	background:transparent;\n"
"}"));
        FavoriteMusicTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FavoriteMusicTable->setShowGrid(false);

        verticalLayout_6->addWidget(FavoriteMusicTable);

        stackedWidget->addWidget(Favoritepage);
        playListpage = new QWidget();
        playListpage->setObjectName(QString::fromUtf8("playListpage"));
        playListpage->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}\n"
"QTableCornerButton::section{\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(playListpage);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        PlayListTable = new QTableWidget(playListpage);
        PlayListTable->setObjectName(QString::fromUtf8("PlayListTable"));
        PlayListTable->setFocusPolicy(Qt::TabFocus);
        PlayListTable->setContextMenuPolicy(Qt::CustomContextMenu);
        PlayListTable->setStyleSheet(QString::fromUtf8("QTableWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"	alternate-background-color: rgba(132, 136, 139, 20);\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section\n"
"{\n"
"	background:transparent;\n"
"}"));
        PlayListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        PlayListTable->setShowGrid(false);
        PlayListTable->setGridStyle(Qt::SolidLine);

        verticalLayout_8->addWidget(PlayListTable);

        stackedWidget->addWidget(playListpage);
        Userpage = new QWidget();
        Userpage->setObjectName(QString::fromUtf8("Userpage"));
        Userpage->setFocusPolicy(Qt::NoFocus);
        Userpage->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	\n"
"	background-color: transparent;\n"
"	/*border: none;*/\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(Userpage);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        AvatarLabel = new QLabel(Userpage);
        AvatarLabel->setObjectName(QString::fromUtf8("AvatarLabel"));
        AvatarLabel->setMinimumSize(QSize(50, 50));
        AvatarLabel->setMaximumSize(QSize(50, 50));
        AvatarLabel->setPixmap(QPixmap(QString::fromUtf8(":/icon/ap")));

        horizontalLayout_5->addWidget(AvatarLabel);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        UsernameLabel = new QLabel(Userpage);
        UsernameLabel->setObjectName(QString::fromUtf8("UsernameLabel"));
        UsernameLabel->setMinimumSize(QSize(200, 20));
        UsernameLabel->setMaximumSize(QSize(200, 20));

        verticalLayout_11->addWidget(UsernameLabel);


        horizontalLayout_5->addLayout(verticalLayout_11);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        horizontalLayout_5->setStretch(2, 10);

        verticalLayout_10->addLayout(horizontalLayout_5);

        tabWidget = new QTabWidget(Userpage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"QTabWidget::tab-bar\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"QTabWidget::pane\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"QTabBar::tab\n"
"{\n"
"	background: transparent;\n"
"}\n"
"\n"
"QTabBar::tab:hover\n"
"{\n"
"	background: rgba(255,255,255,64);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"	background: rgba(255,255,255,128);\n"
"}\n"
"\n"
"QTabBar::tab:disabled\n"
"{\n"
"	width: 0;\n"
"	color: transparent;\n"
"	tab-image: none;\n"
"}"));

        verticalLayout_10->addWidget(tabWidget);

        verticalLayout_10->setStretch(1, 1);
        stackedWidget->addWidget(Userpage);
        lyricsPage = new QWidget();
        lyricsPage->setObjectName(QString::fromUtf8("lyricsPage"));
        lyricsPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_7 = new QVBoxLayout(lyricsPage);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        scrollArea = new QScrollArea(lyricsPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea\n"
"{\n"
"	background: transparent;\n"
"	border: none;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        lyricWidget = new LyricStreamWidget();
        lyricWidget->setObjectName(QString::fromUtf8("lyricWidget"));
        lyricWidget->setGeometry(QRect(0, 0, 57, 16));
        lyricWidget->setStyleSheet(QString::fromUtf8("#lyricWidget\n"
"{\n"
"	background: transparent;\n"
"}"));
        scrollArea->setWidget(lyricWidget);

        verticalLayout_7->addWidget(scrollArea);

        stackedWidget->addWidget(lyricsPage);

        horizontalLayout_3->addWidget(stackedWidget);

        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 0, -1);
        playingCoverLablel = new QLabel(centralwidget);
        playingCoverLablel->setObjectName(QString::fromUtf8("playingCoverLablel"));
        playingCoverLablel->setMinimumSize(QSize(40, 40));

        horizontalLayout_6->addWidget(playingCoverLablel);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 0, 0, -1);
        playingNameLabel = new QLabel(centralwidget);
        playingNameLabel->setObjectName(QString::fromUtf8("playingNameLabel"));
        playingNameLabel->setMinimumSize(QSize(140, 0));

        verticalLayout_4->addWidget(playingNameLabel);

        playingArtistLabel = new QLabel(centralwidget);
        playingArtistLabel->setObjectName(QString::fromUtf8("playingArtistLabel"));
        playingArtistLabel->setMinimumSize(QSize(140, 0));

        verticalLayout_4->addWidget(playingArtistLabel);


        horizontalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout_4->addLayout(horizontalLayout_6);

        back_button = new QPushButton(centralwidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setFocusPolicy(Qt::NoFocus);
        back_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icon/back"), QSize(), QIcon::Normal, QIcon::Off);
        back_button->setIcon(icon15);
        back_button->setFlat(true);

        horizontalLayout_4->addWidget(back_button);

        play_button = new QPushButton(centralwidget);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setFocusPolicy(Qt::NoFocus);
        play_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icon/play"), QSize(), QIcon::Normal, QIcon::Off);
        play_button->setIcon(icon16);
        play_button->setFlat(true);

        horizontalLayout_4->addWidget(play_button);

        forward_button = new QPushButton(centralwidget);
        forward_button->setObjectName(QString::fromUtf8("forward_button"));
        forward_button->setFocusPolicy(Qt::NoFocus);
        forward_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icon/forward"), QSize(), QIcon::Normal, QIcon::Off);
        forward_button->setIcon(icon17);
        forward_button->setFlat(true);

        horizontalLayout_4->addWidget(forward_button);

        now_duration = new QLabel(centralwidget);
        now_duration->setObjectName(QString::fromUtf8("now_duration"));

        horizontalLayout_4->addWidget(now_duration);

        playProgressSlider = new QSlider(centralwidget);
        playProgressSlider->setObjectName(QString::fromUtf8("playProgressSlider"));
        playProgressSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
" \n"
"height:5px;background-color:rgb(219,219,219)\n"
" \n"
"}\n"
"QSlider::handle::horizontal{\n"
"border-image:url(:/icon/handle);\n"
"width:15px;\n"
"margin:-7px -7px -7px -7px;\n"
"}\n"
"QSlider::add-page:horizontal{background-color:rgb(219,219,219);}\n"
"QSlider::sub-page:horizontal{background-color:rgb(26,217,110);}"));
        playProgressSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(playProgressSlider);

        all_duration = new QLabel(centralwidget);
        all_duration->setObjectName(QString::fromUtf8("all_duration"));

        horizontalLayout_4->addWidget(all_duration);

        lyric_button = new QPushButton(centralwidget);
        lyric_button->setObjectName(QString::fromUtf8("lyric_button"));
        lyric_button->setFocusPolicy(Qt::NoFocus);
        lyric_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icon/hide"), QSize(), QIcon::Normal, QIcon::Off);
        lyric_button->setIcon(icon18);
        lyric_button->setFlat(true);

        horizontalLayout_4->addWidget(lyric_button);

        sound_button = new QPushButton(centralwidget);
        sound_button->setObjectName(QString::fromUtf8("sound_button"));
        sound_button->setFocusPolicy(Qt::NoFocus);
        sound_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icon/sound"), QSize(), QIcon::Normal, QIcon::Off);
        sound_button->setIcon(icon19);
        sound_button->setFlat(true);

        horizontalLayout_4->addWidget(sound_button);

        mode_button = new QPushButton(centralwidget);
        mode_button->setObjectName(QString::fromUtf8("mode_button"));
        mode_button->setFocusPolicy(Qt::NoFocus);
        mode_button->setStyleSheet(QString::fromUtf8(""));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icon/list_circle"), QSize(), QIcon::Normal, QIcon::Off);
        mode_button->setIcon(icon20);
        mode_button->setFlat(true);

        horizontalLayout_4->addWidget(mode_button);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\205\267\344\272\221\346\222\255\346\224\276\345\231\250", nullptr));
        logo_button->setText(QCoreApplication::translate("MainWindow", "QooMusic", nullptr));
        search_button->setText(QString());
        menu_button->setText(QString());
        SyncButton->setText(QString());
        LogoutButton->setText(QString());
        min_button->setText(QString());
        normal_button->setText(QString());
        max_button->setText(QString());
        close_button->setText(QString());
        play_list_button->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        local_music_button->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\346\255\214\346\233\262", nullptr));
        my_favorite_button->setText(QCoreApplication::translate("MainWindow", " \346\210\221\347\232\204\345\226\234\346\254\242", nullptr));
        recommond_music_button->setText(QCoreApplication::translate("MainWindow", "\346\257\217\346\227\245\346\216\250\350\215\220", nullptr));
        my_song_list_button->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\346\255\214\345\215\225", nullptr));
        add_list_Button->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\255\214\345\215\225", nullptr));
        AvatarLabel->setText(QString());
        UsernameLabel->setText(QCoreApplication::translate("MainWindow", "username", nullptr));
        playingCoverLablel->setText(QString());
        playingNameLabel->setText(QString());
        playingArtistLabel->setText(QString());
        back_button->setText(QString());
        play_button->setText(QString());
        forward_button->setText(QString());
        now_duration->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        all_duration->setText(QCoreApplication::translate("MainWindow", "11:11", nullptr));
        lyric_button->setText(QString());
        sound_button->setText(QString());
        mode_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
