#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include "notemanager.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void saveNote();
    void openNoteEditWindow(QListWidgetItem *item);

private:
    QLineEdit *inputTitle;
    QTextEdit *inputText;
    QPushButton *saveButton;
    QListWidget *noteList;
    NoteManager *noteManager;
};

#endif // MAINWINDOW_H
