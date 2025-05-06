TEMPLATE = app
TARGET = NoteApp
QT += core gui widgets

# Add include directory
INCLUDEPATH += $$PWD/include

SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/note.cpp \
           src/notemanager.cpp \
           src/notewindow.cpp

HEADERS += include/mainwindow.h \
           include/note.h \
           include/notemanager.h \
           include/notewindow.h

