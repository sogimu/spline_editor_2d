#include "splinepointwidget.h"

SplinePointWidget::SplinePointWidget(Spline *spline, unsigned int pointIndex) :
    _spline( spline ),
    _pointIndex( pointIndex )
{
    setPos( _spline->get(_pointIndex).getPosition().x(), _spline->get(_pointIndex).getPosition().y() );

}

QRectF SplinePointWidget::boundingRect() const
{
    return QRectF( -10, -10, 10, 10 );

}

void SplinePointWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect = QRect( -10, -10, 10, 10 );
    painter->fillRect( rect, QColor(255, 0, 0, 255) );

//    painter->drawText( -25, 0, QString( (int) _spline->get(_dataIndex).getPosition().x() ) + QString(", ") + QString( (int) _spline->get(_dataIndex).getPosition().y() ) );

}

QVariant SplinePointWidget::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value )
{
    if (change == SplinePointWidget::ItemPositionChange)
    {
        QPointF position = QPointF( value.toPointF().x(), value.toPointF().y() );
        std::cout << position.x() << ", " << position.y() << " | " << value.toPointF().x() << ", " << value.toPointF().y() << std::endl;

        _spline->get(_pointIndex).setPosition( position.x(), position.y() );

    }

    return QGraphicsItem::itemChange(change, value);
}
