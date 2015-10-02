#ifndef SPLINEEDITORWIDGET_H
#define SPLINEEDITORWIDGET_H

#include <QGraphicsView>

class SplineEditorWidget : public QGraphicsView
{
public:
    SplineEditorWidget(QWidget *parent);
    ~SplineEditorWidget();

    void setSpline();
    void getSpline();

};

#endif // SPLINEEDITORWIDGET_H
