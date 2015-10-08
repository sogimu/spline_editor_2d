#ifndef SPLINEEDITORWIDGET_H
#define SPLINEEDITORWIDGET_H

#include <cmath>

#include <QGraphicsView>
#include <QKeyEvent>

#include "splinepointwidget.h"
#include "splinelinewidget.h"
#include "spline.h"

class SplineEditorWidget;

class SplineEditorWidget : public QGraphicsView
{
    Q_OBJECT
private:

    Spline *_spline;
    SplinePoint *_selectedPoint;

    bool _is_shift_pressed = false;

public:
    QGraphicsScene *_scene;

    SplineEditorWidget(QWidget *parent);
    ~SplineEditorWidget();

    void setSpline(Spline &spline);
    Spline& getSpline();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    bool isSplineExist();
    bool isPointSelected();
    SplinePoint& getSelectedPoint();

    void redraw();

public slots:
    void selectPoint();
//    void selectPoint(QGraphicsItem *newFocus, QGraphicsItem *oldFocus, Qt::FocusReason reason);

signals:
    void selectedPoint(SplinePoint &point);

    void movedPoint(SplinePoint &point);
    void releasedPoint(SplinePoint &point);
    void pressedPoint(SplinePoint &point);

};

#endif // SPLINEEDITORWIDGET_H
