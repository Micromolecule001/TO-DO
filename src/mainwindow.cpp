#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>
#include "notewindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create central widget and layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QHBoxLayout *mainWindowLayout = new QHBoxLayout(centralWidget);
    QVBoxLayout *noteSaveLayout = new QVBoxLayout();
    QVBoxLayout *noteListLayout = new QVBoxLayout();    // Initialize UI components

    inputTitle = new QLineEdit(this);
    inputTitle->setPlaceholderText("Note Title");
    inputText = new QTextEdit(this);
    inputText->setPlaceholderText("note text");
    saveButton = new QPushButton("Save Note", this);
    noteList = new QListWidget(this);

    // Add components to layout
    noteSaveLayout->addWidget(inputTitle);
    noteSaveLayout->addWidget(inputText);
    noteSaveLayout->addWidget(saveButton);

    noteListLayout->addWidget(noteList);

    mainWindowLayout->addLayout(noteSaveLayout);
    mainWindowLayout->addLayout(noteListLayout);

    // Initialize note manager
    noteManager = new NoteManager();

    // Connect signals to slots
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveNote);
    connect(noteList, &QListWidget::itemDoubleClicked, this, &MainWindow::openNoteEditWindow);

    // Set window properties
    setWindowTitle("Note App");
    resize(400, 500);
}

void MainWindow::saveNote() {
    QString title = inputTitle->text().trimmed();
    QString text = inputText->toPlainText().trimmed();
    if (!title.isEmpty() && !text.isEmpty()) {
        noteManager->addNote(title, text);
        noteList->addItem(title);
        inputTitle->clear();
        inputText->clear();
    }
}

void MainWindow::openNoteEditWindow(QListWidgetItem *item) {
    int index = noteList->row(item);
    Note note = noteManager->getNote(index);
    NoteWindow *noteWindow = new NoteWindow(index, note.getTitle(), note.getText(), this);
    connect(noteWindow, &NoteWindow::noteUpdated, this, [=](int idx, const QString &newTitle, const QString &newText) {
        noteManager->updateNote(idx, newTitle, newText);
        noteList->item(idx)->setText(newTitle);
    });
    noteWindow->exec();
}
