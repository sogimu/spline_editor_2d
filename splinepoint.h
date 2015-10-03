#ifndef SPLINEPOINT_H
#define SPLINEPOINT_H

#include <QVector2D>

class SplinePoint
{
private:
    QVector2D _position;

    double _bias;
    double _continuity;
    double _tension;

public:
    SplinePoint(QVector2D position);
    SplinePoint(double x, double y);

    void setPosition(QVector2D pos) { _position = pos; }
    void setPosition(double x, double y) { _position = QVector2D(x, y); }

    void setBias(double value) { _bias = value; }
    void setContinuity(double value)  { _continuity = value; }
    void setTension(double value)  { _tension = value; }

    QVector2D getPosition() { return _position; }

    double getBias() { return _bias; }
    double getContinuity() { return _continuity; }
    double getTension() { return _tension; }

};

#endif // SPLINEPOINT_H
