#include "continuityhistoryitem.h"

ContinuityHistoryItem::ContinuityHistoryItem(SplinePoint& point, qreal undoContinuity, qreal redoContinuity) :
    _point( point ),
    _undoContinuity( undoContinuity ),
    _redoContinuity( redoContinuity )
{

}

void ContinuityHistoryItem::undo()
{
    _point.setContinuity( _undoContinuity );
}

void ContinuityHistoryItem::redo()
{
    _point.setContinuity( _redoContinuity );
}
