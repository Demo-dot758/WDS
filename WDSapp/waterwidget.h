#ifndef WATERWIDGET_H
#define WATERWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include "scene.h"

class WaterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaterWidget(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
//    void paintEvent(QPaintEvent *event) override;

private:
    Scene * scene;
};

#endif // WATERWIDGET_H
