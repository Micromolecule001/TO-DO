#pragma once
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include "taskmanager.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addTask();
    void toggleTaskStatus(QListWidgetItem* item);

private:
    TaskManager manager;

    QLineEdit* inputField;
    QPushButton* addButton;
    QListWidget* listWidget;

    void refreshTaskList();
};

