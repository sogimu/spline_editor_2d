#include "splinepointwidget.h"

SplinePointWidget::SplinePointWidget(Spline *spline, unsigned int pointIndex) :
    spline( spline ),
    pointIndex( pointIndex )

{
    setPos( spline->positionAt( pointIndex).x(), spline->positionAt( pointIndex).y() );

}

QRectF SplinePointWidget::boundingRect() const
{
    return QRectF( -10, -10, 20, 20 );

}

void SplinePointWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect = QRect( -10, -10, 20, 20 );

    if(isSelected())
    {
        painter->setPen( Qt::red );
        painter->drawEllipse( rect );

    }
    else
    {
        painter->setPen( Qt::green );
        painter->drawEllipse( rect );

    }

//    painter->drawText( -35, -10, QString::number( spline->positionAt(pointIndex).x(), 'f', 1 ) + QString("|") + QString::number( spline->positionAt(pointIndex).y(), 'f', 1 ) );

}

QVariant SplinePointWidget::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant & value )
{
    if (change == SplinePointWidget::ItemPositionChange)
    {
        QPointF position = QPointF( value.toPointF().x(), value.toPointF().y() );
        spline->setPosition( pointIndex, position.x(), position.y() );

    }

    return QGraphicsItem::itemChange(change, value);
}

void SplinePointWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::setSelected(true);
    QGraphicsItem::mousePressEvent(event);
}

void SplinePointWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::setSelected(false);
    QGraphicsItem::mouseReleaseEvent(event);
}


