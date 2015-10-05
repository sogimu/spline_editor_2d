#include "splineserializerjson.h"

SplineSerializerJson::SplineSerializerJson()
{

}

Spline& SplineSerializerJson::Read(QString pathToFile)
{
    QFile file;

    file.setFileName( pathToFile );
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString text = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson( text.toUtf8() );
    QJsonArray splinePoints = document.array();

    Spline *spline = new Spline();

    for( unsigned int i = 0; i < splinePoints.size(); i++ )
    {
        QJsonObject splinePointJson = splinePoints.at( i ).toObject();

        QVector2D splinePointPosition;
        splinePointPosition.setX( splinePointJson["position"].toObject()["x"].toDouble() );
        splinePointPosition.setY( splinePointJson["position"].toObject()["y"].toDouble() );

        qreal bias = splinePointJson["bias"].toDouble();
        qreal continuity = splinePointJson["continuity"].toDouble();
        qreal tension = splinePointJson["tension"].toDouble();

        SplinePoint splinePoint( splinePointPosition );
        splinePoint.setBias( bias );
        splinePoint.setContinuity( continuity );
        splinePoint.setTension( tension );

        spline->push_back( splinePoint );

    }

    return *spline;

}

void SplineSerializerJson::Write(QString pathToFile, Spline& spline)
{
    QFile file;

    file.setFileName( pathToFile );
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.flush();

    QJsonArray splinePoints = QJsonArray();

    for( unsigned int i = 0; i < spline.size(); i++ )
    {
        QJsonObject splinePoint = QJsonObject();

        QJsonObject splinePointPosition = QJsonObject();
        splinePointPosition["x"] = spline.positionAt( i ).x();
        splinePointPosition["y"] = spline.positionAt( i ).y();
        splinePoint["position"] = splinePointPosition;

        splinePoint["bias"] = spline.biasAt( i );
        splinePoint["continuity"] = spline.continuityAt( i );
        splinePoint["tension"] = spline.tensionAt( i );

        splinePoints.append(splinePoint);

    }

    QJsonDocument jsonDocument = QJsonDocument();
    jsonDocument.setArray( splinePoints );

    file.write( jsonDocument.toJson() );
    file.close();

}
