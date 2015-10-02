#include "spline.h"

Spline::Spline():
    _bias( 0.0 ),
    _continuity( 0.0 ),
    _tension( 0.0 ),
    _farthestLeftPoint( QVector2D( 0.0, 0.0 ) ),
    _farthestRightPoint( QVector2D( 0.0, 0.0 ) )
{


}

void Spline::add(SplinePoint point)
{
    _points.push_back( point );
    if( point.getPosition().x() < _farthestLeftPoint.x() || point.getPosition().y() < _farthestLeftPoint.y() )
    {
        _farthestLeftPoint = point.getPosition();
    }
    else
    {
        if( point.getPosition().x() > _farthestRightPoint.x() || point.getPosition().y() > _farthestRightPoint.y() )
        {
            _farthestRightPoint = point.getPosition();
        }
    }
}

void Spline::add(QVector2D point)
{
    SplinePoint splinePoint = SplinePoint( point );
    add( splinePoint );

}

bool Spline::remove(QVector2D point)
{
    bool isSuccess = false;

    for( unsigned int i=0; i < _points.size(); i++ )
    {
        SplinePoint p = _points.at( i );
        if( p.getPosition().x() == point.x() && p.getPosition().y() == point.y() )
        {
            _points.erase( _points.begin() + i );
            isSuccess = true;
            break;
        }

    }

    return isSuccess;

}

bool Spline::remove(SplinePoint point)
{
    return remove( point.getPosition() );

}

SplinePoint& Spline::get(unsigned int index)
{
    return _points.at( index );
}
