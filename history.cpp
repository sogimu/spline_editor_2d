#include "history.h"

History::History():
    _currentIndex( -1 )
{

}

bool History::canUndo()
{
    return _currentIndex >= 0;
}

bool History::canRedo()
{
    return _items.size() > 0 && _currentIndex < _items.size() - 1;
}

void History::undo()
{
    if( !canUndo() )
    {
        return;
    }
    _items[_currentIndex]->undo();

    _currentIndex--;
}

void History::redo()
{
    if( !canRedo() )
    {
        return;
    }
    _currentIndex++;
    _items[_currentIndex]->redo();

}

void History::cutOffHistory()
{
    qint16 index = _currentIndex + 1;
    if( index < _items.size() )
    {
        for(qint16 i=index; i<_items.size(); i++)
        {
            _items.erase( _items.begin() + i );
        }

    }
}

void History::add(QSharedPointer<HistoryItem> item)
{
    cutOffHistory();
    _items.push_back( item );
    _currentIndex++;
}
