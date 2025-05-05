QT += widgets
TEMPLATE = app
TARGET = ToDO-list

INCLUDEPATH += include

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/taskmanager.cpp

HEADERS += \
    include/mainwindow.h \
    include/task.h \
    include/taskmanager.h

