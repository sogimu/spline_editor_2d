#include "splinelinewidget.h"

SplineLineWidget::SplineLineWidget(Spline *spline, unsigned int point0Index, unsigned int point1Index) :
    _spline( spline ),
    _point0Index( point0Index ),
    _point1Index( point1Index )

{
    setPos( 0,0 );

}

QRectF SplineLineWidget::boundingRect() const
{
    QPoint point0;
    QPoint point1;

    point0.setX( std::min( _spline->get( _point0Index ).getPosition().x(), _spline->get( _point1Index ).getPosition().x() ) );
    point0.setY( std::min( _spline->get( _point0Index ).getPosition().y(), _spline->get( _point1Index ).getPosition().y() ) );

    point1.setX( std::max( _spline->get( _point0Index ).getPosition().x(), _spline->get( _point1Index ).getPosition().x() ) );
    point1.setY( std::max( _spline->get( _point0Index ).getPosition().y(), _spline->get( _point1Index ).getPosition().y() ) );

    return QRectF( point0, point1 );

}

void SplineLineWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    prepareGeometryChange();

    //    painter
    QPoint point0;
    QPoint point1;

    point0.setX( _spline->get( _point0Index ).getPosition().x() );
    point0.setY( _spline->get( _point0Index ).getPosition().y() );

    point1.setX( _spline->get( _point1Index ).getPosition().x() );
    point1.setY( _spline->get( _point1Index ).getPosition().y() );

    painter->drawLine( point0, point1 );


}
