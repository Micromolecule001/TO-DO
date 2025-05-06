#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class NoteWindow : public QDialog {
    Q_OBJECT

public:
    NoteWindow(int index, const QString &title, const QString &text, QWidget *parent = nullptr);

signals:
    void noteUpdated(int index, const QString &title, const QString &text);

private slots:
    void saveChanges();

private:
    int noteIndex;
    QLineEdit *editTitle;
    QTextEdit *editText;
    QPushButton *saveButton;
};

#endif // NOTEWINDOW_H
