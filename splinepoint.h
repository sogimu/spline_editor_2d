#ifndef SPLINEPOINT_H
#define SPLINEPOINT_H

#include <QVector2D>

class SplinePoint
{
private:
    QVector2D _position;

public:
    SplinePoint(QVector2D position);
    SplinePoint(double x, double y);

};

#endif // SPLINEPOINT_H
