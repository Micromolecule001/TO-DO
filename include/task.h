#pragma once
#include <QString>
#include <QDate>

struct Task {
    QString text;
    QDate deadline;
    bool completed;

    Task(const QString& t, const QDate& d = QDate::currentDate(), bool c = false)
        : text(t), deadline(d), completed(c) {}
};
