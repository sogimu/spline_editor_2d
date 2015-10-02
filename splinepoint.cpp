#include "splinepoint.h"

SplinePoint::SplinePoint(QVector2D position) :
    _position( position )
{

}

SplinePoint::SplinePoint(double x, double y) :
    _position( QVector2D( x, y ) )
{

}
