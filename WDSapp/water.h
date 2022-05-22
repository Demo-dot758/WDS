#ifndef WATER_H
#define WATER_H

#include <QGraphicsObject>

class Water : public QGraphicsObject
{
    Q_OBJECT
public:
    Water();
    void UpdateWater();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QList<QPoint> wparticlesPositionList;
};

#endif // WATER_H
