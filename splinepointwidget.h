#ifndef SPLINEPOINTWIDGET_H
#define SPLINEPOINTWIDGET_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector2D>

class SplinePointWidget : public QGraphicsItem
{
public:
    SplinePointWidget(QVector2D position);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
protected:
    void advance(int phase);

private:
    qreal _angle, _length;
    QVector2D _position;

};

#endif // SPLINEPOINTWIDGET_H
