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

    void setPosition(QVector2D pos) { _position = pos; }
    void setPosition(double x, double y) { _position = QVector2D(x, y); }

    QVector2D getPosition() { return _position; }


};

#endif // SPLINEPOINT_H
