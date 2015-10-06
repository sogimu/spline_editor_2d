#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QtGlobal>

class HistoryItem
{
public:
    virtual void undo() = 0;
    virtual void redo() = 0;

};

#endif // HISTORYITEM_H
