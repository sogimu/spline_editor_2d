#include "biashistoryitem.h"

BiasHistoryItem::BiasHistoryItem(SplinePoint& point, qreal undoBias, qreal redoBias) :
    _point( point ),
    _undoBias( undoBias ),
    _redoBias( redoBias )
{

}

void BiasHistoryItem::undo()
{
    _point.setBias( _undoBias );
}

void BiasHistoryItem::redo()
{
    _point.setBias( _redoBias );
}
