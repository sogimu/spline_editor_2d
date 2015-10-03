#ifndef SPLINE_H
#define SPLINE_H

#include <vector>
#include <iostream>

#include <QVector2D>
#include <QPoint>
#include <QRect>

#include "splinepoint.h"

struct SplinePointDerivative
{
    double ra;
    double rb;
};

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
//    void add(SplinePoint point);
//    void add(QVector2D point);

    bool remove(QVector2D point);
    bool remove(SplinePoint point);

//    SplinePoint& get(unsigned int index);

//    unsigned int numberOfPoints();

    void push_back(SplinePoint point);
    void push_back(QVector2D point);

    void insert(unsigned int index, SplinePoint point);
    void insert(unsigned int index, QVector2D point);

    void setPosition(unsigned int index, QVector2D position);
    void setPosition(unsigned int index, double x, double y);

    QVector2D positionAt(unsigned int index);
    SplinePointDerivative derivativeAt(unsigned int index);
    double biasAt(unsigned int index);
    double continuityAt(unsigned int index);
    double tensionAt(unsigned int index);

    bool isExistAt(unsigned int index);

    unsigned int size();
    void clear();

    QRect getBoudingRect();

};

#endif // SPLINE_H
