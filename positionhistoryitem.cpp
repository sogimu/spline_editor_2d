#include "positionhistoryitem.h"

PositionHistoryItem::PositionHistoryItem(SplinePoint& point, QVector2D undoPosition, QVector2D redoPosition) :
    _point( point ),
    _undoPosition( undoPosition ),
    _redoPosition( redoPosition )
{

}

void PositionHistoryItem::undo()
{
    _point.setPosition( _undoPosition );
}

void PositionHistoryItem::redo()
{
    _point.setPosition( _redoPosition );
}
