#include "spline.h"

Spline::Spline():
    _farthestLeftPoint( QVector2D( 0.0, 0.0 ) ),
    _farthestRightPoint( QVector2D( 0.0, 0.0 ) ),
    _number_partitions_between_points( 15 )
{

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

void Spline::push_back(SplinePoint point)
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

void Spline::push_back(QVector2D point)
{
    SplinePoint splinePoint = SplinePoint( point );
    push_back( splinePoint );

}

void Spline::insert(unsigned int index, SplinePoint point)
{
    _points.insert( _points.begin() + index, point );
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

void Spline::insert(unsigned int index, QVector2D point)
{
    SplinePoint splinePoint = SplinePoint( point );
    insert( index, splinePoint );

}

void Spline::insert(SplinePoint index_point, QVector2D point)
{
    int index = indexAt( index_point );
    if( index == -1)
    {
        std::cout << "Point not found! Index = " << index_point.getPosition().x() << "|" << index_point.getPosition().y() << std::endl;
    }

    SplinePoint splinePoint = SplinePoint( point );
    insert( index, splinePoint );

}

void Spline::setPosition(unsigned int index, QVector2D position)
{
    _points.at( index ).setPosition( position );
}

void Spline::setPosition(unsigned int index, double x, double y)
{
    _points.at( index ).setPosition( x, y );
}

int Spline::indexAt(QVector2D point)
{
    int index = -1;
    for( unsigned int i=0; i < _points.size(); i++ )
    {
        SplinePoint p = _points.at( i );
        if( p.getPosition().x() == point.x() && p.getPosition().y() == point.y() )
        {
            index = i;
            break;
        }

    }

    return index;

}

int Spline::indexAt(SplinePoint point)
{
    return indexAt( point.getPosition() );

}

SplinePoint& Spline::pointAt(unsigned int index)
{
    return _points.at( index );

}

QVector2D Spline::positionAt(unsigned int index)
{
    return _points.at( index ).getPosition();

}

SplinePointDerivative Spline::derivativeAt(unsigned int index)
{
    SplinePointDerivative res;

    double cur;
    double prev;
    double next;

    if( isExistAt( index-1 ) && isExistAt( index ) && isExistAt( index+1 ) )
    {
        cur = positionAt( index ).y();
        prev = positionAt( index - 1 ).y();
        next = positionAt( index + 1 ).y();

        double g1 = ( cur - prev ) * ( 1 + biasAt( index ) );
        double g2 = ( next - cur ) * ( 1 - biasAt( index ) );
        double g3 = g2 - g1;

        res.ra = ( 1 - tensionAt( index ) ) * ( g1 + 0.5 * g3 * ( 1 + continuityAt( index ) ) );
        res.rb = ( 1 - tensionAt( index ) ) * ( g1 + 0.5 * g3 * ( 1 - continuityAt( index ) ) );
    }
    else
    {
        if( !isExistAt( index-1 ) && isExistAt( index ) && isExistAt( index+1 ) && size() > 2)
        {
            cur = positionAt( index ).y();
            next = positionAt( index + 1 ).y();

            res.ra = next - cur;
            res.rb = (1.5 * (next - cur) - 0.5 * derivativeAt( index + 1 ).ra) * (1 - tensionAt( index ));
        }
        else
        {
            if( isExistAt( index-1 ) && isExistAt( index ) && !isExistAt( index+1 ) && size() > 2 )
            {
                cur = positionAt( index ).y();
                prev = positionAt( index - 1 ).y();

                res.ra = ( 1.5 * ( cur - prev ) - 0.5 * derivativeAt( index - 1).rb ) * (1 - tensionAt( index ) );
                res.rb = cur - prev;

            }
            else
            {
                if( size() == 2 )
                {
                    res.rb = res.ra = ( positionAt( 1 ).y() - positionAt( 0 ).y() ) * (1 - tensionAt( index ) );
                }
                else
                {
                    std::cout << "Is't exist " << index << std::endl;
                }

            }

        }

    }

    return res;

}

double Spline::biasAt(unsigned int index)
{
    return _points.at( index ).getBias();

}

double Spline::continuityAt(unsigned int index)
{
    return _points.at( index ).getContinuity();

}

double Spline::tensionAt(unsigned int index)
{
    return _points.at( index ).getTension();

}

bool Spline::isExistAt(unsigned int index)
{
    if( index < _points.size() )
    {
        return true;
    }
    else
    {
        return false;
    }

}

unsigned int Spline::size()
{
    return _points.size();

}

void Spline::clear()
{
    return _points.clear();

}

void Spline::setNumberPartitionsBetweenPoints(qint16 number)
{
    _number_partitions_between_points = number;
}

qint16 Spline::getNumberPartitionsBetweenPoints()
{
    return _number_partitions_between_points;
}

