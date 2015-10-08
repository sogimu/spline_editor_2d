#include "splinepointwidget.h"

SplinePointWidget::SplinePointWidget(Spline *spline, unsigned int pointIndex) :
    spline( spline ),
    pointIndex( pointIndex ),

    linePenSelected( Qt::red ),
    linePenUnselected( Qt::green )

{
    _oldPosition = spline->positionAt( pointIndex);
    setPos( spline->positionAt( pointIndex).x(), spline->positionAt( pointIndex).y() );

}

QRectF SplinePointWidget::boundingRect() const
{
    return QRectF( -10, -10, 20, 20 );

}

void SplinePointWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect = QRect( -10, -10, 20, 20 );

    if( _oldPosition != spline->positionAt( pointIndex) )
    {
        _oldPosition = spline->positionAt( pointIndex);
        setPos( spline->positionAt( pointIndex).x(), spline->positionAt( pointIndex).y() );

    }

    if(isSelected())
    {
        painter->setPen( linePenSelected );
        painter->drawEllipse( rect );

    }
    else
    {
        painter->setPen( linePenUnselected );
        painter->drawEllipse( rect );

    }

}

QVariant SplinePointWidget::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value )
{
        int d=23;
    if (change == SplinePointWidget::ItemSelectedChange)
    {

        d =+ 23;
    }

    if (change == SplinePointWidget::ItemPositionChange)
    {
        QPointF position = QPointF( value.toPointF().x(), value.toPointF().y() );
        spline->setPosition( pointIndex, position.x(), position.y() );
    }

    return QGraphicsItem::itemChange(change, value);
}

void SplinePointWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    QGraphicsItem::setSelected(true);
    QGraphicsItem::mousePressEvent(event);
}

void SplinePointWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
//    QGraphicsItem::setSelected(false);
    QGraphicsItem::mouseReleaseEvent(event);
}


