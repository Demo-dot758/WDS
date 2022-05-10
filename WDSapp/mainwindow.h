#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "connectiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool getStartStop() {return StartStop;}
    void setStartStop(bool s) {StartStop=s;}

//    virtual void paintEvent(QPaintEvent * event);

private slots:
    void on_pushButtonReset_clicked();

    void on_pushButtonStartStop_clicked();
    void timerslot();

    void Label_show_values();
    void on_actionConnection_triggered();

private:
    Ui::MainWindow *ui;

    QTimer* myTimer;

    bool StartStop;

};
#endif // MAINWINDOW_H
