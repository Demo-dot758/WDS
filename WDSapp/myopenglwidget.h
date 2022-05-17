#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>



class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w,int h) override;
    void paintGL() override;

private:

};

#endif // MYOPENGLWIDGET_H
