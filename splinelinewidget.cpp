#include "splinelinewidget.h"

SplineLineWidget::SplineLineWidget(double localTime0, double localTime1, Spline *spline, unsigned int prevPointIndex, unsigned int nextPointIndex) :
    _localTime0( localTime0 ),
    _localTime1( localTime1),
    _spline( spline ),
    _prevPointIndex( prevPointIndex ),
    _nextPointIndex( nextPointIndex )

{
    setPos( 0,0 );

}

QRectF SplineLineWidget::boundingRect() const
{
    QPoint point0;
    QPoint point1;

    point0.setX( std::min( _spline->positionAt( _prevPointIndex ).x(), _spline->positionAt( _nextPointIndex ).x() ) );
    point0.setY( std::min( _spline->positionAt( _prevPointIndex ).y(), _spline->positionAt( _nextPointIndex ).y() ) );

    point1.setX( std::max( _spline->positionAt( _prevPointIndex ).x(), _spline->positionAt( _nextPointIndex ).x() ) );
    point1.setY( std::max( _spline->positionAt( _prevPointIndex ).y(), _spline->positionAt( _nextPointIndex ).y() ) );

    return QRectF( point0, point1 );

}

void SplineLineWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    prepareGeometryChange();

    //    painter
    QPoint point0;
    QPoint point1;

    point0.setX( _spline->positionAt( _prevPointIndex ).x() );
    point0.setY( _spline->positionAt( _prevPointIndex ).y() );

    point1.setX( _spline->positionAt( _nextPointIndex ).x() );
    point1.setY( _spline->positionAt( _nextPointIndex ).y() );

    painter->drawLine( point0, point1 );


}
