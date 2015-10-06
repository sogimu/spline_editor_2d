#include "tensionhistoryitem.h"

TensionHistoryItem::TensionHistoryItem(SplinePoint& point, qreal undoTension, qreal redoTension) :
    _point( point ),
    _undoTension( undoTension ),
    _redoTension( redoTension )
{

}

void TensionHistoryItem::undo()
{
    _point.setTension( _undoTension );
}

void TensionHistoryItem::redo()
{
    _point.setTension( _redoTension );
}
