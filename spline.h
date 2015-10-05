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

    qint16 _number_partitions_between_points;

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
    void insert(SplinePoint index_point, QVector2D point);

    void setPosition(unsigned int index, QVector2D position);
    void setPosition(unsigned int index, double x, double y);

    int indexAt(SplinePoint point);
    int indexAt(QVector2D point);

    SplinePoint& pointAt(unsigned int index);
    QVector2D positionAt(unsigned int index);
    SplinePointDerivative derivativeAt(unsigned int index);
    double biasAt(unsigned int index);
    double continuityAt(unsigned int index);
    double tensionAt(unsigned int index);

    bool isExistAt(unsigned int index);

    unsigned int size();
    void clear();

    void setNumberPartitionsBetweenPoints(qint16 number);
    qint16 getNumberPartitionsBetweenPoints();

};

#endif // SPLINE_H
