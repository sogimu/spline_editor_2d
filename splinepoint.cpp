#include "splinepoint.h"

SplinePoint::SplinePoint(QVector2D position) :
    _position( position ),
    _bias( 0.0 ),
    _continuity( 0.0 ),
    _tension( 0.0 )
{

}

SplinePoint::SplinePoint(qreal x, qreal y) :
    _position( QVector2D( x, y ) ),
    _bias( 0.0 ),
    _continuity( 0.0 ),
    _tension( 0.0 )
{

}
