#ifndef CONTINUITYHISTORYITEM_H
#define CONTINUITYHISTORYITEM_H

#include "historyitem.h"
#include "splinepoint.h"

class ContinuityHistoryItem : public HistoryItem
{
public:
    ContinuityHistoryItem();
    SplinePoint& _point;

    qreal _undoContinuity;
    qreal _redoContinuity;

    ContinuityHistoryItem(SplinePoint& point, qreal undoContinuity, qreal redoContinuity);

    void undo();
    void redo();

};

#endif // CONTINUITYHISTORYITEM_H
