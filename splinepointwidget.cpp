#include "splinepointwidget.h"

SplinePointWidget::SplinePointWidget(Spline *spline, unsigned int pointIndex) :
    _spline( spline ),
    _pointIndex( pointIndex )
{
    setPos( _spline->positionAt(_pointIndex).x(), _spline->positionAt(_pointIndex).y() );

}

QRectF SplinePointWidget::boundingRect() const
{
    return QRectF( -5, -5, 10, 10 );

}

void SplinePointWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect = QRect( -5, -5, 10, 10 );
//    painter->fillRect( rect, QColor(255, 0, 0, 255) );
    painter->drawEllipse( rect );


//    painter->drawText( -25, 0, QString( (int) _spline->get(_dataIndex).getPosition().x() ) + QString(", ") + QString( (int) _spline->get(_dataIndex).getPosition().y() ) );

}

QVariant SplinePointWidget::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value )
{
    if (change == SplinePointWidget::ItemPositionChange)
    {
        QPointF position = QPointF( value.toPointF().x(), value.toPointF().y() );
        std::cout << position.x() << ", " << position.y() << " | " << value.toPointF().x() << ", " << value.toPointF().y() << std::endl;

        _spline->setPosition(_pointIndex, position.x(), position.y() );

    }

    return QGraphicsItem::itemChange(change, value);
}
