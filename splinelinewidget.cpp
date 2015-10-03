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
    QVector2D point0;
    QVector2D point1;

    QVector2D p1 = _spline->positionAt( _prevPointIndex );
    QVector2D p2 = _spline->positionAt( _nextPointIndex );

    double t0 = _localTime0;
    double t1 = _localTime1;

    double r00 = 300;
    double r01 = 10;

    double r10 = 300;
    double r11 = 10;


    //f(t) = p1 * (2*t^3 - 3*t^2 + 1) + r1 * (t^3 - 2*t^2 + t) + p2 * (-2*t^3 + 3*t^2) + r2 * (t^3 - t^2)

//    point0 = p1 * (2*pow(t0,3) - 3*pow(t0,2) + 1) + r00 * (pow(t0,3) - 2*pow(t0,2) + t0) + p2 * (-2*pow(t0,3) + 3*pow(t0,2)) + r01 * (pow(t0,3) - pow(t0,2));
    point0 = ( p1  * (2*pow(t0,3) - 3*pow(t0,2) + 1) ) + ( p2  * (-2*pow(t0,3) + 3*pow(t0,2)) );
    point0.setX( point0.x() + ( r00 * (pow(t0,3) - 2*pow(t0,2) + t0) ) + ( r01 * (pow(t0,3) - pow(t0,2)) ) );
    point0.setY( point0.y() + ( r00 * (pow(t0,3) - 2*pow(t0,2) + t0) ) + ( r01 * (pow(t0,3) - pow(t0,2)) ) );

    point1 = ( p1 * (2*pow(t1,3) - 3*pow(t1,2) + 1) ) + ( p2 * (-2*pow(t1,3) + 3*pow(t1,2)) );
    point1.setX( point1.x() + ( r10 * (pow(t1,3) - 2*pow(t1,2) + t1) ) + ( r11 * (pow(t1,3) - pow(t1,2)) ) );
    point1.setY( point1.y() + ( r10 * (pow(t1,3) - 2*pow(t1,2) + t1) ) + ( r11 * (pow(t1,3) - pow(t1,2)) ) );


//    point1 = p1 * (2*pow(t1,3) - 3*pow(t1,2) + 1) + r10 * (pow(t1,3) - 2*pow(t1,2) + t1) + p2 * (-2*pow(t1,3) + 3*pow(t1,2)) + r11 * (pow(t1,3) - pow(t1,2));

//    point0.setX( _spline->positionAt( _prevPointIndex ).x() + _localTime0 * _localTime0 );
//    point0.setY( _spline->positionAt( _prevPointIndex ).y() + _localTime0 * _localTime0 );

//    point1.setX( _spline->positionAt( _prevPointIndex ).x() + _localTime1 * _localTime1 );
//    point1.setY( _spline->positionAt( _prevPointIndex ).y() + _localTime1 * _localTime1 );

    painter->drawLine( point0.x(), point0.y(), point1.x(), point1.y() );


}
