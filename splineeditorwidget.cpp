#include "splineeditorwidget.h"
#include "splinepointwidget.h"

SplineEditorWidget::SplineEditorWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    _scene = new QGraphicsScene(this);

    setScene(_scene);

    _scene->addEllipse(QRectF(50.0, 50.0, 100.0, 100.0));
    _scene->addText("Hello, world!");
//    _scene->addWidget(new QPushButton(this));

    _scene->setSceneRect(-200, -200, 300, 300);

    SplinePointWidget *splinePoint = new SplinePointWidget();
    splinePoint->setFlag(QGraphicsItem::ItemIsMovable);
    _scene->addItem(splinePoint);

}

SplineEditorWidget::~SplineEditorWidget()
{

}

void SplineEditorWidget::setSpline(Spline spline)
{

}

Spline SplineEditorWidget::getSpline()
{

}
