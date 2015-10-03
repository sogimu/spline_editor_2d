#ifndef SPLINEPOINT_H
#define SPLINEPOINT_H

#include <QVector2D>

class SplinePoint
{
private:
    QVector2D _position;

    double _derivative;

    double _bias;
    double _continuity;
    double _tension;

public:
    SplinePoint(QVector2D position);
    SplinePoint(double x, double y);

    void setPosition(QVector2D pos) { _position = pos; }
    void setPosition(double x, double y) { _position = QVector2D(x, y); }

    QVector2D getPosition() { return _position; }

    double getDerivative() { return _derivative; }

    double getBias() { return _bias; }
    double getContinuity() { return _continuity; }
    double getTension() { return _tension; }

    void setBias(double value) { _bias = value; }
    void setContinuity(double value)  { _continuity = value; }
    void setTension(double value)  { _tension = value; }


};

#endif // SPLINEPOINT_H
