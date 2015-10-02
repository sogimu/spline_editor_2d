#include "splineeditorwidget.h"
#include "splinepointwidget.h"

SplineEditorWidget::SplineEditorWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    _scene = new QGraphicsScene(this);
    setScene(_scene);

}

SplineEditorWidget::~SplineEditorWidget()
{

}

void SplineEditorWidget::setSpline(Spline spline)
{
    _spline = spline;
    _scene->setSceneRect( _spline.getBoudingRect() );

    _scene->clear();

    for(unsigned int i=0; i < _spline.numberOfPoints(); i++)
    {
        SplinePoint sp = _spline.get( i );
        SplinePointWidget *splinePoint = new SplinePointWidget( sp.getPosition() );
        splinePoint->setFlag( QGraphicsItem::ItemIsMovable );
        _scene->addItem( splinePoint );

    }

}

Spline SplineEditorWidget::getSpline()
{

}
