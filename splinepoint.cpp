#include "splinepoint.h"

SplinePoint::SplinePoint(QVector2D position) :
    _position( position ),
    _bias( 0 ),
    _continuity( 0 ),
    _tension( 1.5 )
{

}

SplinePoint::SplinePoint(double x, double y) :
    _position( QVector2D( x, y ) ),
    _bias( 0.5 ),
    _continuity( 1 ),
    _tension( 0.5 )
{

}
