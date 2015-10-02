#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Spline *spline = new Spline();

    for(int i=0; i<30; i++)
    {
        spline->add( QVector2D(15*i, 0) );

    }

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
