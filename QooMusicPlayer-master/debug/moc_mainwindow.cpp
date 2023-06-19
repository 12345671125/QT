/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[67];
    char stringdata0[1574];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "signalOrderSongPlayed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "Music"
QT_MOC_LITERAL(4, 40, 5), // "music"
QT_MOC_LITERAL(5, 46, 26), // "signalSongDownLoadFinished"
QT_MOC_LITERAL(6, 73, 27), // "signalLyricDownloadFinished"
QT_MOC_LITERAL(7, 101, 27), // "signalCoverDownloadFinished"
QT_MOC_LITERAL(8, 129, 21), // "signalSongPlayStarted"
QT_MOC_LITERAL(9, 151, 22), // "signalSongPlayFinished"
QT_MOC_LITERAL(10, 174, 12), // "signalLogout"
QT_MOC_LITERAL(11, 187, 23), // "on_close_button_clicked"
QT_MOC_LITERAL(12, 211, 21), // "on_max_button_clicked"
QT_MOC_LITERAL(13, 233, 21), // "on_min_button_clicked"
QT_MOC_LITERAL(14, 255, 24), // "on_normal_button_clicked"
QT_MOC_LITERAL(15, 280, 24), // "on_search_button_clicked"
QT_MOC_LITERAL(16, 305, 28), // "on_search_edit_returnPressed"
QT_MOC_LITERAL(17, 334, 34), // "on_searchResultTable_itemActi..."
QT_MOC_LITERAL(18, 369, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(19, 387, 4), // "item"
QT_MOC_LITERAL(20, 392, 47), // "on_searchResultTable_customCo..."
QT_MOC_LITERAL(21, 440, 3), // "pos"
QT_MOC_LITERAL(22, 444, 27), // "on_play_list_button_clicked"
QT_MOC_LITERAL(23, 472, 31), // "on_stackedWidget_currentChanged"
QT_MOC_LITERAL(24, 504, 5), // "index"
QT_MOC_LITERAL(25, 510, 40), // "on_MusicTable_customContextMe..."
QT_MOC_LITERAL(26, 551, 29), // "on_local_music_button_clicked"
QT_MOC_LITERAL(27, 581, 45), // "on_localMusicTable_customCont..."
QT_MOC_LITERAL(28, 627, 38), // "on_searchResultTable_itemDoub..."
QT_MOC_LITERAL(29, 666, 15), // "SlotSongPlayEnd"
QT_MOC_LITERAL(30, 682, 22), // "on_play_button_clicked"
QT_MOC_LITERAL(31, 705, 23), // "on_sound_button_clicked"
QT_MOC_LITERAL(32, 729, 25), // "slotPlayerPositionChanged"
QT_MOC_LITERAL(33, 755, 33), // "on_playProgressSlider_sliderM..."
QT_MOC_LITERAL(34, 789, 8), // "position"
QT_MOC_LITERAL(35, 798, 22), // "on_mode_button_clicked"
QT_MOC_LITERAL(36, 821, 25), // "on_forward_button_clicked"
QT_MOC_LITERAL(37, 847, 30), // "slotExpandPlayingButtonClicked"
QT_MOC_LITERAL(38, 878, 22), // "on_back_button_clicked"
QT_MOC_LITERAL(39, 901, 31), // "on_MusicTable_itemDoubleClicked"
QT_MOC_LITERAL(40, 933, 23), // "on_lyric_button_clicked"
QT_MOC_LITERAL(41, 957, 22), // "adjustCurrentLyricTime"
QT_MOC_LITERAL(42, 980, 5), // "lyric"
QT_MOC_LITERAL(43, 986, 29), // "on_my_favorite_button_clicked"
QT_MOC_LITERAL(44, 1016, 48), // "on_FavoriteMusicTable_customC..."
QT_MOC_LITERAL(45, 1065, 39), // "on_FavoriteMusicTable_itemDou..."
QT_MOC_LITERAL(46, 1105, 30), // "on_my_song_list_button_clicked"
QT_MOC_LITERAL(47, 1136, 26), // "on_add_list_Button_clicked"
QT_MOC_LITERAL(48, 1163, 45), // "on_MusiclistWidget_customCont..."
QT_MOC_LITERAL(49, 1209, 13), // "Play_Playlist"
QT_MOC_LITERAL(50, 1223, 23), // "QList<QListWidgetItem*>"
QT_MOC_LITERAL(51, 1247, 5), // "items"
QT_MOC_LITERAL(52, 1253, 36), // "on_MusiclistWidget_itemDouble..."
QT_MOC_LITERAL(53, 1290, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(54, 1307, 30), // "on_MusiclistWidget_itemClicked"
QT_MOC_LITERAL(55, 1338, 34), // "on_PlayListTable_itemDoubleCl..."
QT_MOC_LITERAL(56, 1373, 43), // "on_PlayListTable_customContex..."
QT_MOC_LITERAL(57, 1417, 22), // "on_logo_button_clicked"
QT_MOC_LITERAL(58, 1440, 23), // "on_LogoutButton_clicked"
QT_MOC_LITERAL(59, 1464, 21), // "on_SyncButton_clicked"
QT_MOC_LITERAL(60, 1486, 19), // "ShowPlaylistTabMenu"
QT_MOC_LITERAL(61, 1506, 10), // "QListView*"
QT_MOC_LITERAL(62, 1517, 3), // "QLV"
QT_MOC_LITERAL(63, 1521, 11), // "lyricScroll"
QT_MOC_LITERAL(64, 1533, 15), // "disappearBgProg"
QT_MOC_LITERAL(65, 1549, 12), // "appearBgProg"
QT_MOC_LITERAL(66, 1562, 11) // "paletteProg"

    },
    "MainWindow\0signalOrderSongPlayed\0\0"
    "Music\0music\0signalSongDownLoadFinished\0"
    "signalLyricDownloadFinished\0"
    "signalCoverDownloadFinished\0"
    "signalSongPlayStarted\0signalSongPlayFinished\0"
    "signalLogout\0on_close_button_clicked\0"
    "on_max_button_clicked\0on_min_button_clicked\0"
    "on_normal_button_clicked\0"
    "on_search_button_clicked\0"
    "on_search_edit_returnPressed\0"
    "on_searchResultTable_itemActivated\0"
    "QTableWidgetItem*\0item\0"
    "on_searchResultTable_customContextMenuRequested\0"
    "pos\0on_play_list_button_clicked\0"
    "on_stackedWidget_currentChanged\0index\0"
    "on_MusicTable_customContextMenuRequested\0"
    "on_local_music_button_clicked\0"
    "on_localMusicTable_customContextMenuRequested\0"
    "on_searchResultTable_itemDoubleClicked\0"
    "SlotSongPlayEnd\0on_play_button_clicked\0"
    "on_sound_button_clicked\0"
    "slotPlayerPositionChanged\0"
    "on_playProgressSlider_sliderMoved\0"
    "position\0on_mode_button_clicked\0"
    "on_forward_button_clicked\0"
    "slotExpandPlayingButtonClicked\0"
    "on_back_button_clicked\0"
    "on_MusicTable_itemDoubleClicked\0"
    "on_lyric_button_clicked\0adjustCurrentLyricTime\0"
    "lyric\0on_my_favorite_button_clicked\0"
    "on_FavoriteMusicTable_customContextMenuRequested\0"
    "on_FavoriteMusicTable_itemDoubleClicked\0"
    "on_my_song_list_button_clicked\0"
    "on_add_list_Button_clicked\0"
    "on_MusiclistWidget_customContextMenuRequested\0"
    "Play_Playlist\0QList<QListWidgetItem*>\0"
    "items\0on_MusiclistWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0on_MusiclistWidget_itemClicked\0"
    "on_PlayListTable_itemDoubleClicked\0"
    "on_PlayListTable_customContextMenuRequested\0"
    "on_logo_button_clicked\0on_LogoutButton_clicked\0"
    "on_SyncButton_clicked\0ShowPlaylistTabMenu\0"
    "QListView*\0QLV\0lyricScroll\0disappearBgProg\0"
    "appearBgProg\0paletteProg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       4,  350, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  254,    2, 0x06 /* Public */,
       5,    1,  257,    2, 0x06 /* Public */,
       6,    1,  260,    2, 0x06 /* Public */,
       7,    1,  263,    2, 0x06 /* Public */,
       8,    1,  266,    2, 0x06 /* Public */,
       9,    1,  269,    2, 0x06 /* Public */,
      10,    0,  272,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  273,    2, 0x08 /* Private */,
      12,    0,  274,    2, 0x08 /* Private */,
      13,    0,  275,    2, 0x08 /* Private */,
      14,    0,  276,    2, 0x08 /* Private */,
      15,    0,  277,    2, 0x08 /* Private */,
      16,    0,  278,    2, 0x08 /* Private */,
      17,    1,  279,    2, 0x08 /* Private */,
      20,    1,  282,    2, 0x08 /* Private */,
      22,    0,  285,    2, 0x08 /* Private */,
      23,    1,  286,    2, 0x08 /* Private */,
      25,    1,  289,    2, 0x08 /* Private */,
      26,    0,  292,    2, 0x08 /* Private */,
      27,    1,  293,    2, 0x08 /* Private */,
      28,    1,  296,    2, 0x08 /* Private */,
      29,    0,  299,    2, 0x08 /* Private */,
      30,    0,  300,    2, 0x08 /* Private */,
      31,    0,  301,    2, 0x08 /* Private */,
      32,    0,  302,    2, 0x08 /* Private */,
      33,    1,  303,    2, 0x08 /* Private */,
      35,    0,  306,    2, 0x08 /* Private */,
      36,    0,  307,    2, 0x08 /* Private */,
      37,    0,  308,    2, 0x08 /* Private */,
      38,    0,  309,    2, 0x08 /* Private */,
      39,    1,  310,    2, 0x08 /* Private */,
      40,    0,  313,    2, 0x08 /* Private */,
      41,    1,  314,    2, 0x08 /* Private */,
      43,    0,  317,    2, 0x08 /* Private */,
      44,    1,  318,    2, 0x08 /* Private */,
      45,    1,  321,    2, 0x08 /* Private */,
      46,    0,  324,    2, 0x08 /* Private */,
      47,    0,  325,    2, 0x08 /* Private */,
      48,    1,  326,    2, 0x08 /* Private */,
      49,    1,  329,    2, 0x08 /* Private */,
      52,    1,  332,    2, 0x08 /* Private */,
      54,    1,  335,    2, 0x08 /* Private */,
      55,    1,  338,    2, 0x08 /* Private */,
      56,    1,  341,    2, 0x08 /* Private */,
      57,    0,  344,    2, 0x08 /* Private */,
      58,    0,  345,    2, 0x08 /* Private */,
      59,    0,  346,    2, 0x08 /* Private */,
      60,    1,  347,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void, 0x80000000 | 53,   19,
    QMetaType::Void, 0x80000000 | 53,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::QPoint,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 61,   62,

 // properties: name, type, flags
      63, QMetaType::Int, 0x00095103,
      64, QMetaType::Int, 0x00095103,
      65, QMetaType::Int, 0x00095103,
      66, QMetaType::Double, 0x00095003,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalOrderSongPlayed((*reinterpret_cast< Music(*)>(_a[1]))); break;
        case 1: _t->signalSongDownLoadFinished((*reinterpret_cast< Music(*)>(_a[1]))); break;
        case 2: _t->signalLyricDownloadFinished((*reinterpret_cast< Music(*)>(_a[1]))); break;
        case 3: _t->signalCoverDownloadFinished((*reinterpret_cast< Music(*)>(_a[1]))); break;
        case 4: _t->signalSongPlayStarted((*reinterpret_cast< Music(*)>(_a[1]))); break;
        case 5: _t->signalSongPlayFinished((*reinterpret_cast< Music(*)>(_a[1]))); break;
        case 6: _t->signalLogout(); break;
        case 7: _t->on_close_button_clicked(); break;
        case 8: _t->on_max_button_clicked(); break;
        case 9: _t->on_min_button_clicked(); break;
        case 10: _t->on_normal_button_clicked(); break;
        case 11: _t->on_search_button_clicked(); break;
        case 12: _t->on_search_edit_returnPressed(); break;
        case 13: _t->on_searchResultTable_itemActivated((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->on_searchResultTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: _t->on_play_list_button_clicked(); break;
        case 16: _t->on_stackedWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_MusicTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 18: _t->on_local_music_button_clicked(); break;
        case 19: _t->on_localMusicTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 20: _t->on_searchResultTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 21: _t->SlotSongPlayEnd(); break;
        case 22: _t->on_play_button_clicked(); break;
        case 23: _t->on_sound_button_clicked(); break;
        case 24: _t->slotPlayerPositionChanged(); break;
        case 25: _t->on_playProgressSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_mode_button_clicked(); break;
        case 27: _t->on_forward_button_clicked(); break;
        case 28: _t->slotExpandPlayingButtonClicked(); break;
        case 29: _t->on_back_button_clicked(); break;
        case 30: _t->on_MusicTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 31: _t->on_lyric_button_clicked(); break;
        case 32: _t->adjustCurrentLyricTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 33: _t->on_my_favorite_button_clicked(); break;
        case 34: _t->on_FavoriteMusicTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 35: _t->on_FavoriteMusicTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 36: _t->on_my_song_list_button_clicked(); break;
        case 37: _t->on_add_list_Button_clicked(); break;
        case 38: _t->on_MusiclistWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 39: _t->Play_Playlist((*reinterpret_cast< QList<QListWidgetItem*>(*)>(_a[1]))); break;
        case 40: _t->on_MusiclistWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 41: _t->on_MusiclistWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 42: _t->on_PlayListTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 43: _t->on_PlayListTable_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 44: _t->on_logo_button_clicked(); break;
        case 45: _t->on_LogoutButton_clicked(); break;
        case 46: _t->on_SyncButton_clicked(); break;
        case 47: _t->ShowPlaylistTabMenu((*reinterpret_cast< QListView*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 47:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QListView* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(Music );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalOrderSongPlayed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Music );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSongDownLoadFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Music );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalLyricDownloadFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Music );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalCoverDownloadFinished)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Music );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSongPlayStarted)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(Music );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSongPlayFinished)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalLogout)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getLyricScroll(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getDisappearBgProg(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getAppearBgProg(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getPaletteBgProg(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLyricScroll(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setDisappearBgProg(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setAppearBgProg(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setPaletteBgProg(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainWindow::signalOrderSongPlayed(Music _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalSongDownLoadFinished(Music _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signalLyricDownloadFinished(Music _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalCoverDownloadFinished(Music _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signalSongPlayStarted(Music _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signalSongPlayFinished(Music _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::signalLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
