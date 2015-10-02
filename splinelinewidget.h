#ifndef SPLINELINEWIDGET_H
#define SPLINELINEWIDGET_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector2D>

#include <QVariant>

#include <iostream>
#include <algorithm>

#include "spline.h"
#include "splinepoint.h"

class SplineLineWidget : public QGraphicsItem
{
public:
    SplineLineWidget(Spline *spline, unsigned int point0Index, unsigned int point1Index);
    QRectF boundingRect() const;

    void paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
//protected:
//    void advance(int phase);

private:
    Spline *_spline;
    unsigned int _point0Index;
    unsigned int _point1Index;

};


#endif // SPLINELINEWIDGET_H
