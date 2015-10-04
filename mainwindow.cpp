#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->splineEditor, &SplineEditorWidget::selectedPoint, this, &MainWindow::splineEditor_SelectedPoint );

    Spline *spline = new Spline();

    for(int i=0; i<10; i++)
    {
        spline->push_back( QVector2D( i * 50, sin( i ) * 50 ) );

    }

//    spline->insert( 1, QVector2D( 25, 25 ) );

    ui->splineEditor->setSpline( spline );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_DeletePushButton_clicked()
{
    Spline *spline = ui->splineEditor->getSpline();
    Spline spline2;

}

void MainWindow::splineEditor_SelectedPoint(SplinePoint& point)
{
    ui->biasLineEdit->setText(       QString::number( point.getBias(),         'f', 1 ) );
    ui->continuityLineEdit->setText( QString::number( point.getContinuity(),   'f', 1 ) );
    ui->tensionLineEdit->setText(    QString::number( point.getTension(),      'f', 1 ) );

    ui->positionXLineEdit->setText(  QString::number( point.getPosition().x(), 'f', 1 ) );
    ui->positionYLineEdit->setText(  QString::number( point.getPosition().y(), 'f', 1 ) );

    std::cout << "wlefkmwlef" << point.getPosition().x() << std::endl;
}
