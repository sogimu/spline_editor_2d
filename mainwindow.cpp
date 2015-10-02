#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Spline spline;
    spline.add( QVector2D(0,0) );
    spline.add( QVector2D(100,0) );
    spline.add( QVector2D(200,0) );
    spline.add( QVector2D(300,0) );
    spline.add( QVector2D(400,0) );
    spline.add( QVector2D(500,0) );
    spline.add( QVector2D(600,0) );
    spline.add( QVector2D(700,0) );
    spline.add( QVector2D(800,0) );

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
