#pragma once

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

public slots:
    void startTimer(int minutes);
    void pauseTimer();
    void resetTimer();
    void saveNote(const QString &text);
    QString loadNote();

signals:
    void tick(int secondsLeft);
    void phaseChanged(const QString &phase);

private:
    QString currentNote;
};