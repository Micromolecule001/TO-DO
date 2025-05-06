#include "note.h"

Note::Note(const QString &title, const QString &text) : title(title), text(text) {}

QString Note::getTitle() const {
    return title;
}

QString Note::getText() const {
    return text;
}

void Note::setTitle(const QString &title) {
    this->title = title;
}

void Note::setText(const QString &text) {
    this->text = text;
}
