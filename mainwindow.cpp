#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _selectedPoint(0)
{
    ui->setupUi(this);

    QObject::connect(ui->splineEditor, &SplineEditorWidget::selectedPoint, this, &MainWindow::splineEditor_SelectedPoint );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    Spline *spline = new Spline();

    for(int i=0; i<3; i++)
    {
        spline->push_back( QVector2D( i * 50, sin( i ) * 50 ) );

    }

    ui->splineEditor->setSpline( *spline );

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
    if(_selectedPoint)
    {
        Spline &spline = ui->splineEditor->getSpline();
        spline.insert( *_selectedPoint, QVector2D( _selectedPoint->getPosition().x(), _selectedPoint->getPosition().y() + 75 ) );
        ui->splineEditor->setSpline( spline );

    }

}

void MainWindow::on_DeletePushButton_clicked()
{
    if(_selectedPoint)
    {
        Spline &spline = ui->splineEditor->getSpline();
        spline.remove( *_selectedPoint );
        ui->splineEditor->setSpline( spline );

    }


}

void MainWindow::splineEditor_SelectedPoint(SplinePoint& point)
{
    _selectedPoint = &point;
    ui->biasLineEdit->setText(       QString::number( point.getBias(),         'f', 1 ) );
    ui->continuityLineEdit->setText( QString::number( point.getContinuity(),   'f', 1 ) );
    ui->tensionLineEdit->setText(    QString::number( point.getTension(),      'f', 1 ) );

    ui->biasHorizontalSlider->setValue(       static_cast<int>( point.getBias()       ) );
    ui->continuityHorizontalSlider->setValue( static_cast<int>( point.getContinuity() ) );
    ui->tensionHorizontalSlider->setValue(    static_cast<int>( point.getTension()    ) );

    ui->positionXLineEdit->setText(  QString::number( point.getPosition().x(), 'f', 1 ) );
    ui->positionYLineEdit->setText(  QString::number( point.getPosition().y(), 'f', 1 ) );

}

void MainWindow::on_biasLineEdit_textChanged(const QString &arg1)
{
    if(_selectedPoint)
    {
        _selectedPoint->setBias( arg1.toDouble() );
    }
}

void MainWindow::on_continuityLineEdit_textChanged(const QString &arg1)
{
    if(_selectedPoint)
    {
        _selectedPoint->setContinuity( arg1.toDouble() );
    }

}

void MainWindow::on_tensionLineEdit_textChanged(const QString &arg1)
{
    if(_selectedPoint)
    {
        _selectedPoint->setTension( arg1.toDouble() );
    }

}

void MainWindow::on_positionXLineEdit_editingFinished()
{
    if(_selectedPoint)
    {
        _selectedPoint->setPosition( ui->positionXLineEdit->text().toDouble(), _selectedPoint->getPosition().y() );
    }

}

void MainWindow::on_positionYLineEdit_editingFinished()
{
    if(_selectedPoint)
    {
        _selectedPoint->setPosition( _selectedPoint->getPosition().x(), ui->positionYLineEdit->text().toDouble()  );
    }

}

void MainWindow::on_biasHorizontalSlider_sliderMoved(int position)
{
    if(_selectedPoint)
    {
        ui->biasLineEdit->setText( QString::number(position) );
    }

}

void MainWindow::on_continuityHorizontalSlider_sliderMoved(int position)
{
    if(_selectedPoint)
    {
        ui->continuityLineEdit->setText( QString::number(position) );
    }

}

void MainWindow::on_tensionHorizontalSlider_sliderMoved(int position)
{
    if(_selectedPoint)
    {
        ui->tensionLineEdit->setText( QString::number(position) );
    }

}

void MainWindow::on_biasLineEdit_editingFinished()
{

}

void MainWindow::on_partitionsNumberHorizontalSlider_sliderMoved(int position)
{
    Spline &spline = ui->splineEditor->getSpline();
    spline.setNumberPartitionsBetweenPoints( position );
    ui->splineEditor->setSpline( spline );

}
