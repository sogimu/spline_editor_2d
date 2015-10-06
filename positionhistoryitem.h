#ifndef POSITIONHISTORYITEM_H
#define POSITIONHISTORYITEM_H

#include "historyitem.h"
#include "splinepoint.h"

class PositionHistoryItem : public HistoryItem
{
private:

public:
    SplinePoint& _point;

    QVector2D _undoPosition;
    QVector2D _redoPosition;

    PositionHistoryItem(SplinePoint& point, QVector2D undoPosition, QVector2D redoPosition);

    void undo();
    void redo();

};

#endif // POSITIONHISTORYITEM_H
