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
    qreal ra;
    qreal rb;
};

class Spline
{
private:
    std::vector<SplinePoint> _points;

    qint16 _number_partitions_between_points;

public:
    Spline();

    bool remove(QVector2D point);
    bool remove(SplinePoint point);

    void push_back(SplinePoint point);
    void push_back(QVector2D point);

    void insert(unsigned int index, SplinePoint point);
    void insert(unsigned int index, QVector2D point);
    void insert(SplinePoint index_point, QVector2D point);

    void setPosition(unsigned int index, QVector2D position);
    void setPosition(unsigned int index, qreal x, qreal y);

    int indexAt(SplinePoint point);
    int indexAt(QVector2D point);

    SplinePoint& pointAt(unsigned int index);
    QVector2D positionAt(unsigned int index);
    SplinePointDerivative derivativeAt(unsigned int index);
    qreal biasAt(unsigned int index);
    qreal continuityAt(unsigned int index);
    qreal tensionAt(unsigned int index);

    bool isExistAt(unsigned int index);

    unsigned int size();
    void clear();

    void setNumberPartitionsBetweenPoints(qint16 number);
    qint16 getNumberPartitionsBetweenPoints();

};

#endif // SPLINE_H
