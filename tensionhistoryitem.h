#ifndef TENSIONHISTORYIITEM_H
#define TENSIONHISTORYIITEM_H

#include "historyitem.h"
#include "splinepoint.h"

class TensionHistoryItem : public HistoryItem
{
public:
    TensionHistoryItem();
    SplinePoint& _point;

    qreal _undoTension;
    qreal _redoTension;

    TensionHistoryItem(SplinePoint& point, qreal undoTension, qreal redoTension);

    void undo();
    void redo();

};

#endif // TENSIONHISTORYIITEM_H
