#ifndef SPLINE_H
#define SPLINE_H

#include <vector>
#include <QVector2D>
#include "splinepoint.h"

class Spline
{
private:
    std::vector<SplinePoint> _points;

    double _bias;
    double _continuity;
    double _tension;

public:
    Spline();
    void addPoint(SplinePoint point);
    void addPoint(QVector2D point);

    void removePoint(SplinePoint point);
    void removePoint(QVector2D point);
    void removePoint(int index);

    double getBias();
    double getContinuity();
    double getTension();

    double setBias(double value);
    double setContinuity(double value);
    double setTension(double value);

};

#endif // SPLINE_H
