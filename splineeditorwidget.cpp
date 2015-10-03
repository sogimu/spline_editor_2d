#include "splineeditorwidget.h"

SplineEditorWidget::SplineEditorWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    _scene = new QGraphicsScene(this);
    setScene(_scene);

}

SplineEditorWidget::~SplineEditorWidget()
{

}

void SplineEditorWidget::setSpline(Spline *spline)
{
    _spline = spline;

    _scene->clear();

    for(unsigned int i=0; i < _spline->size(); i++)
    {
        SplinePointWidget *splinePoint = new SplinePointWidget( _spline, i );
        splinePoint->setFlag( QGraphicsItem::ItemIsMovable );
        splinePoint->setFlag( QGraphicsItem::ItemSendsScenePositionChanges, true);
        _scene->addItem( splinePoint );

    }

    for(unsigned int i=1; i < _spline->size(); i++)
    {
        SplineLineWidget *splineLine = new SplineLineWidget( _spline, i-1, i);
        _scene->addItem( splineLine );

    }

}

Spline* SplineEditorWidget::getSpline()
{
    return _spline;
}
