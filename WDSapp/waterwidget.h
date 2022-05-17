#ifndef WATERWIDGET_H
#define WATERWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>

class WaterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WaterWidget(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
//    void paintEvent(QPaintEvent *event) override;
};

#endif // WATERWIDGET_H
