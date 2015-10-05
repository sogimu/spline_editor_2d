#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <math.h>

#include <QMainWindow>
#include <QString>

#include "splinepoint.h"
#include "splineserializer.h"
#include "splineserializerjson.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void splineEditor_SelectedPoint(SplinePoint& point);

private slots:
    void on_actionExit_triggered();

    void on_DeletePushButton_clicked();

    void on_biasLineEdit_textChanged(const QString &arg1);

    void on_continuityLineEdit_textChanged(const QString &arg1);

    void on_tensionLineEdit_textChanged(const QString &arg1);

    void on_positionXLineEdit_editingFinished();


    void on_positionYLineEdit_editingFinished();

    void on_biasHorizontalSlider_sliderMoved(int position);

    void on_continuityHorizontalSlider_sliderMoved(int position);

    void on_tensionHorizontalSlider_sliderMoved(int position);

    void on_AddPushButton_clicked();

    void on_biasLineEdit_editingFinished();

    void on_actionSaveAs_triggered();

    void on_actionOpen_triggered();

    void on_partitionsNumberHorizontalSlider_sliderMoved(int position);

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;

    SplinePoint *_selectedPoint;

};

#endif // MAINWINDOW_H
