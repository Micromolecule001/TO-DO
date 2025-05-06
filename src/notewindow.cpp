#include "notewindow.h"
#include <QVBoxLayout>

NoteWindow::NoteWindow(int index, const QString &title, const QString &text, QWidget *parent)
    : QDialog(parent), noteIndex(index) {
    // Create layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Initialize UI components
    editTitle = new QLineEdit(this);
    editTitle->setText(title);
    editText = new QTextEdit(this);
    editText->setText(text);
    saveButton = new QPushButton("Save Changes", this);

    // Add components to layout
    layout->addWidget(editTitle);
    layout->addWidget(editText);
    layout->addWidget(saveButton);

    // Connect button to slot
    connect(saveButton, &QPushButton::clicked, this, &NoteWindow::saveChanges);

    // Set window properties
    setWindowTitle("Edit Note");
    resize(300, 400);
}

void NoteWindow::saveChanges() {
    QString title = editTitle->text().trimmed();
    QString text = editText->toPlainText().trimmed();
    if (!title.isEmpty() && !text.isEmpty()) {
        emit noteUpdated(noteIndex, title, text);
        accept();
    }
}
