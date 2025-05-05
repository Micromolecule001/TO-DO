#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    QHBoxLayout* inputLayout = new QHBoxLayout();

    inputField = new QLineEdit(this);
    inputField->setPlaceholderText("Enter task...");
    addButton = new QPushButton("Add", this);
    inputLayout->addWidget(inputField);
    inputLayout->addWidget(addButton);

    listWidget = new QListWidget(this);

    layout->addLayout(inputLayout);
    layout->addWidget(listWidget);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::toggleTaskStatus);

    setCentralWidget(central);
    setWindowTitle("To-Do List");
    resize(400, 300);
}

void MainWindow::addTask() {
    QString text = inputField->text();
    if (!text.isEmpty()) {
        Task task(text);
        manager.addTask(task);
        inputField->clear();
        refreshTaskList();
    }
}

void MainWindow::toggleTaskStatus(QListWidgetItem* item) {
    int index = listWidget->row(item);
    manager.toggleCompleted(index);
    refreshTaskList();
}

void MainWindow::refreshTaskList() {
    listWidget->clear();
    const auto& tasks = manager.getTasks();
    for (const Task& task : tasks) {
        QString display = task.completed ? "[✔] " : "[ ] ";
        display += task.text;
        listWidget->addItem(display);
    }
}

