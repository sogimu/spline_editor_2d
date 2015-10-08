#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <math.h>

#include <QMainWindow>
#include <QString>
#include <QDebug>

#include "splinepoint.h"
#include "splineserializer.h"
#include "splineserializerjson.h"

#include "history.h"

#include "positionhistoryitem.h"
#include "biashistoryitem.h"
#include "continuityhistoryitem.h"
#include "tensionhistoryitem.h"

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
    void splineEditor_MovedPoint(SplinePoint& point);
    void splineEditor_PressedPoint(SplinePoint& point);
    void splineEditor_ReleasedPoint(SplinePoint& point);


private slots:    
    void on_AddPushButton_clicked();

    void on_DeletePushButton_clicked();


    void on_biasLineEdit_textChanged(const QString &arg1);

    void on_continuityLineEdit_textChanged(const QString &arg1);

    void on_tensionLineEdit_textChanged(const QString &arg1);


    void on_positionXLineEdit_editingFinished();

    void on_positionYLineEdit_editingFinished();


    void on_biasHorizontalSlider_sliderMoved(int position);

    void on_continuityHorizontalSlider_sliderMoved(int position);

    void on_tensionHorizontalSlider_sliderMoved(int position);

    void on_partitionsNumberHorizontalSlider_sliderMoved(int position);


    void on_actionNew_triggered();

    void on_actionSaveAs_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;

    SplinePoint *_selectedPoint;

    QVector2D lastPointPosition;

    History *_history;

};

#endif // MAINWINDOW_H
