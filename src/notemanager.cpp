#include "notemanager.h"

NoteManager::NoteManager() {}

void NoteManager::addNote(const QString &title, const QString &text) {
    notes.append(Note(title, text));
}

void NoteManager::updateNote(int index, const QString &title, const QString &text) {
    if (index >= 0 && index < notes.size()) {
        notes[index].setTitle(title);
        notes[index].setText(text);
    }
}

QVector<Note> NoteManager::getNotes() const {
    return notes;
}

Note NoteManager::getNote(int index) const {
    if (index >= 0 && index < notes.size()) {
        return notes[index];
    }
    return Note("", "");
}
