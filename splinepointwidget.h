#ifndef SPLINEPOINTWIDGET_H
#define SPLINEPOINTWIDGET_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector2D>

class SplinePointWidget : public QGraphicsItem
{
public:
    SplinePointWidget();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
protected:
    void advance(int phase);

private:
    qreal angle, length;
    QVector2D position;

};

#endif // SPLINEPOINTWIDGET_H
