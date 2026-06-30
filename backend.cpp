#include "Backend.h"
#include <QDebug>

Backend::Backend(QObject *parent)
    : QObject(parent)
{
}

void Backend::startTimer(int minutes)
{
    qDebug() << "startTimer called with" << minutes << "minutes";
    emit phaseChanged(QStringLiteral("Focus"));
}

void Backend::pauseTimer()
{
    qDebug() << "pauseTimer called";
}

void Backend::resetTimer()
{
    qDebug() << "resetTimer called";
    emit phaseChanged(QStringLiteral("Idle"));
}

void Backend::saveNote(const QString &text)
{
    currentNote = text;
    qDebug() << "Note saved:" << text;
}

QString Backend::loadNote()
{
    return currentNote;
}