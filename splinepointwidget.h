#ifndef SPLINEPOINTWIDGET_H
#define SPLINEPOINTWIDGET_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector2D>

#include <QVariant>

#include <iostream>

#include "spline.h"
#include "splinepoint.h"

class SplinePointWidget : public QGraphicsItem
{
public:
    SplinePointWidget(Spline *spline, unsigned int pointIndex);
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Spline *spline;
    unsigned int pointIndex;


protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value );
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:

};

#endif // SPLINEPOINTWIDGET_H
