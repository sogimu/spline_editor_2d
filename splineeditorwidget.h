#ifndef SPLINEEDITORWIDGET_H
#define SPLINEEDITORWIDGET_H

#include <QGraphicsView>
#include "spline.h"

class SplineEditorWidget : public QGraphicsView
{
private:
    QGraphicsScene *_scene;

public:
    SplineEditorWidget(QWidget *parent);
    ~SplineEditorWidget();

    void setSpline(Spline spline);
    Spline getSpline();

};

#endif // SPLINEEDITORWIDGET_H
