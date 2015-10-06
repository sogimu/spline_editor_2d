#ifndef SPLINELINEWIDGET_H
#define SPLINELINEWIDGET_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector2D>

#include <QVariant>

#include <iostream>
#include <algorithm>
#include <cmath>

#include "spline.h"
#include "splinepoint.h"

class SplineLineWidget : public QGraphicsItem
{
public:
    SplineLineWidget(qreal localTime0, qreal localTime1, Spline *spline, unsigned int prevPointIndex, unsigned int nextPointIndex);
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal _localTime0;
    qreal _localTime1;
    Spline *_spline;
    unsigned int _prevPointIndex;
    unsigned int _nextPointIndex;

    QRectF _boundingRect;

};


#endif // SPLINELINEWIDGET_H
