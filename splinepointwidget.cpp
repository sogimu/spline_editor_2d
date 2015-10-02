#include "splinepointwidget.h"

SplinePointWidget::SplinePointWidget()
{
    // random start rotation
    this->angle = (qrand() % 360);
    setRotation(this->angle);

    // set the speed
    this->length = 5;  // 5 pixels

    // random start position
    int startX = 0;
    int startY = 0;

    if(qrand() % 1)
    {
        startX = qrand() % 200;
        startY = qrand() % 200;
    }
    else
    {
        startX = qrand() % -100;
        startY = qrand() % -100;
    }

    this->position.setX(startX);
    this->position.setY(startY);

    setPos(this->position.x(), this->position.y());

}

QRectF SplinePointWidget::boundingRect() const
{
    return QRect(-10,-10,50,50);
}

void SplinePointWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect rect = QRect(-10,-10,20,20);

    this->angle += 0.01;
    setRotation(this->angle);

    painter->drawEllipse(rect);
//    painter->drawRect(rect);

    painter->drawRect(0, -3, 30, 5);


}

void SplinePointWidget::advance(int phase)
{
    if(!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0, -length));
}
