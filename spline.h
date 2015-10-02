#ifndef SPLINE_H
#define SPLINE_H

#include <vector>
#include <QVector2D>
#include <QPoint>
#include <QRect>

#include "splinepoint.h"

class Spline
{
private:
    std::vector<SplinePoint> _points;

    double _bias;
    double _continuity;
    double _tension;

    QVector2D _farthestLeftPoint;
    QVector2D _farthestRightPoint;

public:
    Spline();
    void add(SplinePoint point);
    void add(QVector2D point);

    bool remove(QVector2D point);
    bool remove(SplinePoint point);
//    void removePoint(int index);

    SplinePoint& get(unsigned int index);
//    SplinePoint get(QVector2D point);
    std::vector<SplinePoint>* getData();

    double getBias() { return _bias; }
    double getContinuity() { return _continuity; }
    double getTension() { return _tension; }

    unsigned int numberOfPoints() { return _points.size(); }

    void setBias(double value) { _bias = value; }
    void setContinuity(double value)  { _continuity = value; }
    void setTension(double value)  { _tension = value; }

    QRect getBoudingRect();

};

#endif // SPLINE_H
