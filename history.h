#ifndef HISTORY_H
#define HISTORY_H

#include <QList>
#include <QSharedPointer>

#include "historyitem.h"
#include "spline.h"
#include "splinepoint.h"

class History
{
private:
    QList<QSharedPointer<HistoryItem> > _items;
    qint16 _currentIndex;

public:
    History();

    bool canUndo();
    bool canRedo();

    void undo();
    void redo();
    void cutOffHistory();
    void add(QSharedPointer<HistoryItem> item);
};

#endif // HISTORY_H
