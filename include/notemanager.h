#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QVector>
#include "note.h"

class NoteManager {
public:
    NoteManager();
    void addNote(const QString &title, const QString &text);
    void updateNote(int index, const QString &title, const QString &text);
    QVector<Note> getNotes() const;
    Note getNote(int index) const;

private:
    QVector<Note> notes;
};

#endif // NOTEMANAGER_H
