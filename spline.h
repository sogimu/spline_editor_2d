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

//    std::vector::insert();
//    std::vector::push_back();
//    std::vector::pop_back();

    QVector2D _farthestLeftPoint;
    QVector2D _farthestRightPoint;

public:
    Spline();
    void add(SplinePoint point);
    void add(QVector2D point);

    bool remove(QVector2D point);
    bool remove(SplinePoint point);

    SplinePoint& get(unsigned int index);

    unsigned int numberOfPoints();
    QRect getBoudingRect();

    void push_back(SplinePoint point);
    void push_back(QVector2D point);

    void insert(unsigned int index, SplinePoint point);
    void insert(unsigned int index, QVector2D point);

    SplinePoint& at(unsigned int index);
    unsigned int size();
    void clear();

};

#endif // SPLINE_H
