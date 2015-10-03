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
    QVector2D point0;
    QVector2D point1;

    QVector2D p1 = _spline->positionAt( _prevPointIndex );
    QVector2D p2 = _spline->positionAt( _nextPointIndex );

    double t0 = _localTime0;
    double t1 = _localTime1;

    double r00 = _spline->derivativeAt( _prevPointIndex ).ra;
    double r01 = _spline->derivativeAt( _nextPointIndex ).rb;

    double r10 = r00;
    double r11 = r01;

    point0 = ( p1  * (2*pow(t0,3) - 3*pow(t0,2) + 1) ) + ( p2  * (-2*pow(t0,3) + 3*pow(t0,2)) );
    point0.setX( point0.x() + ( r00 * (pow(t0,3) - 2*pow(t0,2) + t0) ) + ( r01 * (pow(t0,3) - pow(t0,2)) ) );
    point0.setY( point0.y() + ( r00 * (pow(t0,3) - 2*pow(t0,2) + t0) ) + ( r01 * (pow(t0,3) - pow(t0,2)) ) );

    point1 = ( p1 * (2*pow(t1,3) - 3*pow(t1,2) + 1) ) + ( p2 * (-2*pow(t1,3) + 3*pow(t1,2)) );
    point1.setX( point1.x() + ( r10 * (pow(t1,3) - 2*pow(t1,2) + t1) ) + ( r11 * (pow(t1,3) - pow(t1,2)) ) );
    point1.setY( point1.y() + ( r10 * (pow(t1,3) - 2*pow(t1,2) + t1) ) + ( r11 * (pow(t1,3) - pow(t1,2)) ) );

    return QRectF( QPoint( std::min(point0.x(), point1.x()), std::min( point0.y(), point1.y() ) ), QPoint( std::max( point0.x(), point1.x() ), std::max( point0.y(), point1.y() ) ) );


}

void SplineLineWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    prepareGeometryChange();

    //    painterss
    QVector2D point0;
    QVector2D point1;

    QVector2D p1 = _spline->positionAt( _prevPointIndex );
    QVector2D p2 = _spline->positionAt( _nextPointIndex );

    double t0 = _localTime0;
    double t1 = _localTime1;

    double r00 = _spline->derivativeAt( _prevPointIndex ).ra;
    double r01 = _spline->derivativeAt( _nextPointIndex ).rb;

    double r10 = r00;
    double r11 = r01;

    point0 = ( p1  * (2*pow(t0,3) - 3*pow(t0,2) + 1) ) + ( p2  * (-2*pow(t0,3) + 3*pow(t0,2)) );
    point0.setX( point0.x() + ( r00 * (pow(t0,3) - 2*pow(t0,2) + t0) ) + ( r01 * (pow(t0,3) - pow(t0,2)) ) );
    point0.setY( point0.y() + ( r00 * (pow(t0,3) - 2*pow(t0,2) + t0) ) + ( r01 * (pow(t0,3) - pow(t0,2)) ) );

    point1 = ( p1 * (2*pow(t1,3) - 3*pow(t1,2) + 1) ) + ( p2 * (-2*pow(t1,3) + 3*pow(t1,2)) );
    point1.setX( point1.x() + ( r10 * (pow(t1,3) - 2*pow(t1,2) + t1) ) + ( r11 * (pow(t1,3) - pow(t1,2)) ) );
    point1.setY( point1.y() + ( r10 * (pow(t1,3) - 2*pow(t1,2) + t1) ) + ( r11 * (pow(t1,3) - pow(t1,2)) ) );

    painter->drawLine( point0.x(), point0.y(), point1.x(), point1.y() );

}
