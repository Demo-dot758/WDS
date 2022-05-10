#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

class MyOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();
protected:
    void initializeGL() override;
    void resizeGL(int w,int h) override;
    void paintGL() override;
};

#endif // MYOPENGLWIDGET_H
