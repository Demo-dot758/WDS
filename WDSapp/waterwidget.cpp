#include "waterwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include "water.h"
#include "waterparticle.h"
#include "scene.h"
#include "glass.h"


WaterWidget::WaterWidget(QWidget *parent)
    : QWidget{parent}
{

//    scene = new Scene(this);
//    scene->setSceneRect(-390,-290,780,580);



    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QColor(Qt::white)));
    QGraphicsView *view = new QGraphicsView(this);

//    view->fitInView(WaterWidget::size());
//    view->fitInView(0,0,781,581);
    view->setScene(scene);
//    scene->setSceneRect(-200,-400,200,400);
//    view->setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
//    view->setMinimumSize(781,581);
//    scene->setMinimumRenderSize(500);

//    view->setScene(scene);

    view->resize(781,581);

//    Glass * glass = new Glass();
//    scene->addItem(glass);

    QPolygon polyPoints;
    polyPoints << QPoint(250,250);  //x1
    polyPoints << QPoint(270,250);  //x2
    polyPoints << QPoint(270,500);  //x3
    polyPoints << QPoint(300,530);  //x4
    polyPoints << QPoint(390,530);  //x5
    polyPoints << QPoint(420,500);  //x6
    polyPoints << QPoint(420,250);  //x7
    polyPoints << QPoint(440,250);  //x8
    polyPoints << QPoint(440,510);  //x9
    polyPoints << QPoint(400,550);  //x10
    polyPoints << QPoint(290,550);  //x11
    polyPoints << QPoint(250,510);  //x12

    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::black);

    QGraphicsPolygonItem * polyItem = new QGraphicsPolygonItem(polyPoints);
    polyItem->setPen(mPen);
    polyItem->setBrush(Qt::gray);
//    QTransform transformPoly = polyItem->transform();
//    transformPoly.rotate(45);
//    polyItem->setTransform(transformPoly);
    scene->addItem(polyItem);


    QGraphicsEllipseItem * circleItem = new QGraphicsEllipseItem(300,300,2,2);
    circleItem->setPen(Qt::NoPen);
    circleItem->setBrush(Qt::blue);

    scene->addItem(circleItem);
}

//void WaterWidget::paintEvent(QPaintEvent *event)
//{
//    QPen mPen;
//    mPen.setWidth(3);
//    mPen.setColor(Qt::black);

//    QPainter painter(this);
//    painter.setPen(mPen);
//    painter.setBrush(Qt::gray);

//    QPolygon points;
//    points << QPoint(250,250);  //x1
//    points << QPoint(270,250);  //x2
//    points << QPoint(270,500);  //x3
//    points << QPoint(300,530);  //x4
//    points << QPoint(390,530);  //x5
//    points << QPoint(420,500);  //x6
//    points << QPoint(420,250);  //x7
//    points << QPoint(440,250);  //x8
//    points << QPoint(440,510);  //x9
//    points << QPoint(400,550);  //x10
//    points << QPoint(290,550);  //x11
//    points << QPoint(250,510);  //x12

//    painter.drawPolygon(points);



//    painter.setPen(Qt::NoPen);
//    painter.setBrush(Qt::blue);
//    for(int i=0;i<146;i++)
//    {
//        for(int j=0;j<198;j++)
//        {
//            painter.drawEllipse(QRectF(272+(i),300+(j),2,2));
//        }
//    }
//}
