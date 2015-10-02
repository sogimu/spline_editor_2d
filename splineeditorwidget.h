#ifndef SPLINEEDITORWIDGET_H
#define SPLINEEDITORWIDGET_H

#include <QGraphicsView>
#include "splinepointwidget.h"
#include "splinelinewidget.h"
#include "spline.h"

class SplineEditorWidget : public QGraphicsView
{
private:
    QGraphicsScene *_scene;

    Spline *_spline;

public:
    SplineEditorWidget(QWidget *parent);
    ~SplineEditorWidget();

    void setSpline(Spline *spline);
    Spline* getSpline();

};

#endif // SPLINEEDITORWIDGET_H
