#include "splinepointwidget.h"

SplinePointWidget::SplinePointWidget(QVector2D position) :
    _position( position ),
    _angle( qrand() % 360 ),
    _length( 5 )
{
    setRotation( _angle );
    setPos( _position.x(), _position.y() );

}

QRectF SplinePointWidget::boundingRect() const
{
    return QRect(-10,-10,50,50);
}

void SplinePointWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect = QRect(-10,-10,20,20);

    _angle += 0.01;
    setRotation( _angle );

    painter->drawEllipse( rect );
    painter->drawRect(0, -3, 30, 5);

}

void SplinePointWidget::advance(int phase)
{
    if(!phase) return;

    QPointF location = pos();

    setPos(mapToParent(0, -_length));
}
