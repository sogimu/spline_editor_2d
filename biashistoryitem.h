#ifndef BIASHISTORYITEM_H
#define BIASHISTORYITEM_H

#include "historyitem.h"
#include "splinepoint.h"

class BiasHistoryItem : public HistoryItem
{
public:
    BiasHistoryItem();
    SplinePoint& _point;

    qreal _undoBias;
    qreal _redoBias;

    BiasHistoryItem(SplinePoint& point, qreal undoBias, qreal redoBias);

    void undo();
    void redo();

};

#endif // BIASHISTORYITEM_H
