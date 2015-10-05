#ifndef SPLINEEDITORWIDGET_H
#define SPLINEEDITORWIDGET_H

#include <cmath>

#include <QGraphicsView>

#include "splinepointwidget.h"
#include "splinelinewidget.h"
#include "spline.h"

class SplineEditorWidget : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *_scene;

    Spline *_spline;

public:
    SplineEditorWidget(QWidget *parent);
    ~SplineEditorWidget();

    void setSpline(Spline &spline);
    Spline& getSpline();

public slots:
    void selectPoint();

signals:
    void selectedPoint(SplinePoint &point);

};

#endif // SPLINEEDITORWIDGET_H
