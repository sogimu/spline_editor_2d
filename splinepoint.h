#ifndef SPLINEPOINT_H
#define SPLINEPOINT_H

#include <QVector2D>

class SplinePoint
{
private:
    QVector2D _position;

    qreal _bias;
    qreal _continuity;
    qreal _tension;

public:
    SplinePoint(QVector2D position);
    SplinePoint(qreal x, qreal y);

    void setPosition(QVector2D pos) { _position = pos; }
    void setPosition(qreal x, qreal y) { _position = QVector2D(x, y); }

    void setBias(qreal value) { _bias = value; }
    void setContinuity(qreal value)  { _continuity = value; }
    void setTension(qreal value)  { _tension = value; }

    QVector2D getPosition() { return _position; }

    qreal getBias() { return _bias; }
    qreal getContinuity() { return _continuity; }
    qreal getTension() { return _tension; }

};

#endif // SPLINEPOINT_H
