#include "splineeditorwidget.h"

SplineEditorWidget::SplineEditorWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    _scene = new QGraphicsScene(this);
    setScene(_scene);
    setRenderHint(QPainter::Antialiasing, true);

    QObject::connect( _scene, &QGraphicsScene::selectionChanged, this,  &SplineEditorWidget::selectPoint );

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
        splinePoint->setFlag( QGraphicsItem::ItemIsSelectable );
        splinePoint->setFlag( QGraphicsItem::ItemSendsScenePositionChanges, true);
        _scene->addItem( splinePoint );

    }

    for(unsigned int i=1; i < _spline->size(); i++)
    {
        for(unsigned int j=1; j <= 10; j++)
        {
            double localTime0 = (1.0 / 10) * (j-1);
            double localTime1 = (1.0 / 10) * j;
            SplineLineWidget *splineLine = new SplineLineWidget( localTime0, localTime1, _spline, i-1, i);
            _scene->addItem( splineLine );

        }

    }

}

Spline* SplineEditorWidget::getSpline()
{
    return _spline;
}

void SplineEditorWidget::selectPoint()
{
    QList<QGraphicsItem *> items = _scene->selectedItems();

    if(items.size() > 0)
    {
        SplinePointWidget *splinePoint = dynamic_cast<SplinePointWidget*>( items.at(0) );
        emit this->selectedPoint( _spline->pointAt( splinePoint->pointIndex ) );

    }

}

void SplineEditorWidget::a(SplinePoint& point)
{
    std::cout << "wlefkmwlef" << point.getPosition().x() << std::endl;
}

