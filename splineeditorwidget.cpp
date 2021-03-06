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
//    QObject::connect( _scene, &QGraphicsScene::focusItemChanged, this,  &SplineEditorWidget::selectPoint );

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

//void SplineEditorWidget::selectPoint(QGraphicsItem *newFocus, QGraphicsItem *oldFocus, Qt::FocusReason reason)
void SplineEditorWidget::selectPoint()
{
    QList<QGraphicsItem *> items = _scene->selectedItems();

    if(items.size() > 0)
    {
        SplinePointWidget *splinePoint = dynamic_cast<SplinePointWidget*>( items.at(0) );
        _selectedPoint = &( _spline->pointAt( splinePoint->pointIndex ) );
        emit this->selectedPoint( *_selectedPoint );

    }
    else
    {
        _selectedPoint = 0;
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

    if(_is_shift_pressed)
    {
        std::cout << mapToScene(event->pos()).x() << "|" << mapToScene(event->pos()).y() << std::endl;

        if(event->buttons() == Qt::LeftButton)
        {
            if( isSplineExist() )
            {
                Spline &spline = getSpline();
                spline.push_back( QVector2D( mapToScene(event->pos()).x(), mapToScene(event->pos()).y() ) );
                setSpline( spline );

            }

        }

        if(event->buttons() == Qt::RightButton)
        {
            if( isSplineExist() )
            {
                if( isPointSelected() )
                {
                    Spline &spline = getSpline();
                    SplinePoint& selectedPoint = getSelectedPoint();
                    spline.remove( selectedPoint );
                    setSpline( spline );

                }
            }

        }
    }

}

void SplineEditorWidget::keyPressEvent(QKeyEvent *event)
{
    if( event->modifiers() == Qt::ShiftModifier )
    {
        _is_shift_pressed = true;
        std::cout << "is_shift_pressed = true" << std::endl;

    }
    else
    {
        QGraphicsView::keyPressEvent(event);
    }

}

void SplineEditorWidget::keyReleaseEvent(QKeyEvent *event)
{

//    int dd = event->modifiers();
//    std::cout << dd << std::endl;

//    if( event->modifiers() == Qt::ShiftModifier )
//    {
        _is_shift_pressed = false;
        std::cout << "is_shift_pressed = false" << std::endl;

//    }
//    else
//    {
        QGraphicsView::keyReleaseEvent(event);
//    }

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
