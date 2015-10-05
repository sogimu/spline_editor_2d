#ifndef SPLINEFACTORYJSON_H
#define SPLINEFACTORYJSON_H

#include <QString>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>

#include "splineserializer.h"

class SplineSerializerJson : public SplineSerializer
{
public:
    SplineSerializerJson();

    static Spline& Read(QString pathToFile);
    static void Write(QString pathToFile, Spline &spline);

};

#endif // SPLINEFACTORYJSON_H
