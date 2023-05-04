QT       += core gui #包含的模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets#大于qt4版本才包含此模块

CONFIG += c++11 #使用的语言

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS  # 定义编译选项，表示的是有些工程标记为过时了，编译器就会发出警告

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \    #源文件
    main.cpp \
    widget.cpp

HEADERS += \    #头文件
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
