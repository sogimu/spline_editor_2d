#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _history( new History() )
{
    ui->setupUi(this);

    QObject::connect(ui->splineEditor, &SplineEditorWidget::movedPoint, this, &MainWindow::splineEditor_MovedPoint );
    QObject::connect(ui->splineEditor, &SplineEditorWidget::pressedPoint, this, &MainWindow::splineEditor_PressedPoint );
    QObject::connect(ui->splineEditor, &SplineEditorWidget::releasedPoint, this, &MainWindow::splineEditor_ReleasedPoint );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    Spline *spline = new Spline();

    for(int i=0; i<10; i++)
    {
        spline->push_back( QVector2D( i * 50, sin( i ) * 50 ) );

    }

    ui->splineEditor->setSpline( *spline );

    _history = new History();

}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName( this, tr("Open Spline"), QString(""), tr("Spline File (*.spline *.json)") );
    if (!fileName.isEmpty())
    {
        Spline& spline = SplineSerializerJson::Read( fileName );

        ui->splineEditor->setSpline( spline );

    }

}

void MainWindow::on_actionSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName( this, tr("Save Spline"), QString(""), tr("Spline File (*.spline *.json)") );
    if (!fileName.isEmpty())
    {
        SplineSerializerJson::Write( fileName, ui->splineEditor->getSpline() );

    }

}


void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_AddPushButton_clicked()
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            Spline &spline = ui->splineEditor->getSpline();
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();
            spline.insert( selectedPoint, QVector2D( selectedPoint.getPosition().x(), selectedPoint.getPosition().y() + 75 ) );
            ui->splineEditor->setSpline( spline );

        }
        else
        {
            Spline &spline = ui->splineEditor->getSpline();
            QVector2D lastPointPosition = spline.positionAt( spline.size() - 1 );

            spline.push_back( QVector2D( lastPointPosition.x() + 50, lastPointPosition.y() ) );
            ui->splineEditor->setSpline( spline );

        }


    }

}

void MainWindow::on_DeletePushButton_clicked()
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            Spline &spline = ui->splineEditor->getSpline();
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();
            spline.remove( selectedPoint );
            ui->splineEditor->setSpline( spline );
        }

    }

}

void MainWindow::splineEditor_MovedPoint(SplinePoint& point)
{
    ui->biasLineEdit->setText(       QString::number( point.getBias(),         'f', 1 ) );
    ui->continuityLineEdit->setText( QString::number( point.getContinuity(),   'f', 1 ) );
    ui->tensionLineEdit->setText(    QString::number( point.getTension(),      'f', 1 ) );

    ui->biasHorizontalSlider->setValue(       static_cast<int>( point.getBias()       ) );
    ui->continuityHorizontalSlider->setValue( static_cast<int>( point.getContinuity() ) );
    ui->tensionHorizontalSlider->setValue(    static_cast<int>( point.getTension()    ) );

    ui->positionXLineEdit->setText(  QString::number( point.getPosition().x(), 'f', 1 ) );
    ui->positionYLineEdit->setText(  QString::number( point.getPosition().y(), 'f', 1 ) );

}

void MainWindow::splineEditor_PressedPoint(SplinePoint& point)
{
    lastPointPosition = point.getPosition();
    ui->biasLineEdit->setText(       QString::number( point.getBias(),         'f', 1 ) );
    ui->continuityLineEdit->setText( QString::number( point.getContinuity(),   'f', 1 ) );
    ui->tensionLineEdit->setText(    QString::number( point.getTension(),      'f', 1 ) );

    ui->biasHorizontalSlider->setValue(       static_cast<int>( point.getBias()       ) );
    ui->continuityHorizontalSlider->setValue( static_cast<int>( point.getContinuity() ) );
    ui->tensionHorizontalSlider->setValue(    static_cast<int>( point.getTension()    ) );

    ui->positionXLineEdit->setText(  QString::number( point.getPosition().x(), 'f', 1 ) );
    ui->positionYLineEdit->setText(  QString::number( point.getPosition().y(), 'f', 1 ) );

}

void MainWindow::splineEditor_ReleasedPoint(SplinePoint& point)
{
    if( ui->splineEditor->isSplineExist() )
    {
        if( ui->splineEditor->isPointSelected() )
        {
            QVector2D undoPosition = QVector2D( lastPointPosition.x(), lastPointPosition.y() );
            QVector2D redoPosition = QVector2D( point.getPosition().x(), point.getPosition().y() );

            QSharedPointer<HistoryItem> item = QSharedPointer<HistoryItem> ( new PositionHistoryItem( point, undoPosition, redoPosition ) );

            _history->add( item );
        }
    }

}

void MainWindow::on_biasLineEdit_textChanged(const QString &arg1)
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();

            qreal undoBias = selectedPoint.getBias();

            selectedPoint.setBias( arg1.toDouble() );
            ui->splineEditor->redraw();

            qreal redoBias = selectedPoint.getBias();
            QSharedPointer<HistoryItem> item = QSharedPointer<HistoryItem> ( new BiasHistoryItem( selectedPoint, undoBias, redoBias ) );

            _history->add( item );

        }

    }
}

void MainWindow::on_continuityLineEdit_textChanged(const QString &arg1)
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();

            qreal undoContinuity = selectedPoint.getBias();

            selectedPoint.setContinuity( arg1.toDouble() );
            ui->splineEditor->redraw();

            qreal redoContinuity = selectedPoint.getContinuity();
            QSharedPointer<HistoryItem> item = QSharedPointer<HistoryItem> ( new ContinuityHistoryItem( selectedPoint, undoContinuity, redoContinuity ) );

            _history->add( item );


        }
    }

}

void MainWindow::on_tensionLineEdit_textChanged(const QString &arg1)
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();

            qreal undoTension = selectedPoint.getTension();

            selectedPoint.setTension( arg1.toDouble() );
            ui->splineEditor->redraw();

            qreal redoTension = selectedPoint.getTension();
            QSharedPointer<HistoryItem> item = QSharedPointer<HistoryItem> ( new TensionHistoryItem( selectedPoint, undoTension, redoTension ) );

            _history->add( item );


        }
    }

}

void MainWindow::on_positionXLineEdit_editingFinished()
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();

            QVector2D undoPosition = QVector2D( selectedPoint.getPosition().x(), selectedPoint.getPosition().y() );

            selectedPoint.setPosition( ui->positionXLineEdit->text().toDouble(), selectedPoint.getPosition().y() );
            ui->splineEditor->redraw();

            QVector2D redoPosition = QVector2D( selectedPoint.getPosition().x(), selectedPoint.getPosition().y() );

            QSharedPointer<HistoryItem> item = QSharedPointer<HistoryItem> ( new PositionHistoryItem( selectedPoint, undoPosition, redoPosition ) );

            _history->add( item );

        }

    }

}

void MainWindow::on_positionYLineEdit_editingFinished()
{
    if( ui->splineEditor->isSplineExist() )
    {

        if( ui->splineEditor->isPointSelected() )
        {
            SplinePoint& selectedPoint = ui->splineEditor->getSelectedPoint();

            QVector2D undoPosition = QVector2D( selectedPoint.getPosition().x(), selectedPoint.getPosition().y() );

            selectedPoint.setPosition( selectedPoint.getPosition().x(), ui->positionYLineEdit->text().toDouble() );
            ui->splineEditor->redraw();

            QVector2D redoPosition = QVector2D( selectedPoint.getPosition().x(), selectedPoint.getPosition().y() );

            QSharedPointer<HistoryItem> item = QSharedPointer<HistoryItem> ( new PositionHistoryItem( selectedPoint, undoPosition, redoPosition ) );

            _history->add( item );

        }

    }

}

void MainWindow::on_biasHorizontalSlider_sliderMoved(int position)
{
    if( ui->splineEditor->isSplineExist() )
    {
        ui->biasLineEdit->setText( QString::number(position) );
        ui->splineEditor->redraw();

    }

}

void MainWindow::on_continuityHorizontalSlider_sliderMoved(int position)
{
    if( ui->splineEditor->isSplineExist() )
    {
        ui->continuityLineEdit->setText( QString::number(position) );
        ui->splineEditor->redraw();
    }

}

void MainWindow::on_tensionHorizontalSlider_sliderMoved(int position)
{
    if( ui->splineEditor->isSplineExist() )
    {
        ui->tensionLineEdit->setText( QString::number(position) );
        ui->splineEditor->redraw();
    }

}

void MainWindow::on_partitionsNumberHorizontalSlider_sliderMoved(int position)
{
    if( ui->splineEditor->isSplineExist() )
    {
        Spline &spline = ui->splineEditor->getSpline();
        spline.setNumberPartitionsBetweenPoints( position );
        ui->splineEditor->setSpline( spline );
    }

}

void MainWindow::on_actionUndo_triggered()
{
    _history->undo();
    ui->splineEditor->redraw();

}

void MainWindow::on_actionRedo_triggered()
{
    _history->redo();
    ui->splineEditor->redraw();

}
