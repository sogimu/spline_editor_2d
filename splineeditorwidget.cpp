#include "splineeditorwidget.h"

SplineEditorWidget::SplineEditorWidget(QWidget *parent) :
    QGraphicsView(parent),
    _spline( 0 ),
    _selectedPoint( 0 )
{
    _scene = new QGraphicsScene(this);
    setScene(_scene);
    setRenderHint(QPainter::Antialiasing, true);

    QObject::connect( _scene, &QGraphicsScene::selectionChanged, this,  &SplineEditorWidget::selectPoint );

}

SplineEditorWidget::~SplineEditorWidget()
{

}

void SplineEditorWidget::setSpline(Spline &spline)
{
    _spline = &spline;

    _scene->clear();
    _scene->update( _scene->itemsBoundingRect() );

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
        qint16 number_partitions_between_points = _spline->getNumberPartitionsBetweenPoints();
        for(unsigned int j=1; j <= number_partitions_between_points; j++)
        {
            qreal localTime0 = ( 1.0 / number_partitions_between_points ) * ( j-1 );
            qreal localTime1 = ( 1.0 / number_partitions_between_points ) * j;
            SplineLineWidget *splineLine = new SplineLineWidget( localTime0, localTime1, _spline, i-1, i );
            _scene->addItem( splineLine );
            splineLine->show();

        }

    }

}

Spline& SplineEditorWidget::getSpline()
{
    return *_spline;
}

void SplineEditorWidget::selectPoint()
{
    QList<QGraphicsItem *> items = _scene->selectedItems();

    if(items.size() > 0)
    {
        SplinePointWidget *splinePoint = dynamic_cast<SplinePointWidget*>( items.at(0) );
        _selectedPoint = &( _spline->pointAt( splinePoint->pointIndex ) );
        emit this->selectedPoint( *_selectedPoint );

    }

}

void SplineEditorWidget::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    QList<QGraphicsItem *> items = _scene->selectedItems();
    if(items.size() > 0)
    {
        SplinePointWidget *splinePoint = dynamic_cast<SplinePointWidget*>( items.at(0) );
        emit movedPoint( _spline->pointAt( splinePoint->pointIndex ) );

    }

}

void SplineEditorWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QList<QGraphicsItem *> items = _scene->selectedItems();

    if(items.size() > 0)
    {
        SplinePointWidget *splinePoint = dynamic_cast<SplinePointWidget*>( items.at(0) );
        emit releasedPoint( _spline->pointAt( splinePoint->pointIndex ) );

    }

    QGraphicsView::mouseReleaseEvent(event);

}

void SplineEditorWidget::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    QList<QGraphicsItem *> items = _scene->selectedItems();
    if(items.size() > 0)
    {
        SplinePointWidget *splinePoint = dynamic_cast<SplinePointWidget*>( items.at(0) );
        emit pressedPoint( _spline->pointAt( splinePoint->pointIndex ) );

    }

}

bool SplineEditorWidget::isSplineExist()
{
    return _spline == 0 ? false : true;
}

bool SplineEditorWidget::isPointSelected()
{
    if( isSplineExist() && _selectedPoint != 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

SplinePoint& SplineEditorWidget::getSelectedPoint()
{
    if( isPointSelected() )
    {
        return *_selectedPoint;
    }
    else
    {
        throw new std::exception();
    }

}

void SplineEditorWidget::redraw()
{
    _scene->update( _scene->itemsBoundingRect() );

}
