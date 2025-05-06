#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note {
public:
    Note(const QString &title, const QString &text);
    QString getTitle() const;
    QString getText() const;
    void setTitle(const QString &title);
    void setText(const QString &text);

private:
    QString title;
    QString text;
};

#endif // NOTE_H
