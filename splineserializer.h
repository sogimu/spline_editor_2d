#ifndef SPLINEFACTORY_H
#define SPLINEFACTORY_H

#include <QString>
#include <QFileDialog>

#include "spline.h"

class SplineSerializer
{
public:
    SplineSerializer();
    static Spline Read(QString pathToFile);
    static void Write(QString pathToFile, Spline &spline);

};

#endif // SPLINEFACTORY_H
