#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectiondialog.h"
#include <QTimer>
#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectionDialog dialog;
    myTimer = new QTimer(this);
    myTimer->setInterval(500);
    myTimer->setSingleShot(false);
    connect(myTimer, SIGNAL(timeout()),this, SLOT(timerslot()));
    myTimer->start();

    connect(&dialog,SIGNAL(timeout()),this,SLOT(Label_show_values()));

}
MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);

//    QPen pen;
//    pen.setColor(Qt::black);
//    pen.setWidth(5);

//    painter.setPen(pen);
//    painter.drawLines()
//}

void MainWindow::timerslot()
{
}

void MainWindow::Label_show_values()
{
    ConnectionDialog dialog;
//    QTimer tim;
//    tim.setInterval(500);
//    tim.setSingleShot(false);
//    connect(tim, SIGNAL(timeout()),this, SLOT(timerslot()));
//    if(StartStop==true)
//    {
        ui->labelX->setText(dialog.getAccX());
        ui->labelY->setText(dialog.getAccY());
//    }else
//        ui->labelX->setText("Stop");
}
void MainWindow::on_pushButtonReset_clicked()
{
    ui->statusbar->showMessage("Restart",2000);
}


void MainWindow::on_pushButtonStartStop_clicked()
{
    if ( this->myTimer->isActive() == true ) {
            this->myTimer->stop();
            ui->pushButtonStartStop->setText("Stop");
            ui->statusbar->showMessage("Appliaction started",2000);
            setStartStop(true);
        } else {
            this->myTimer->start(500);
            ui->pushButtonStartStop->setText("Start");
            ui->statusbar->showMessage("Appliaction stopped",2000);
            setStartStop(false);
        }
}


void MainWindow::on_actionConnection_triggered()
{
    ConnectionDialog * dialog = new ConnectionDialog(this);
    int ret = dialog->exec();

    if(ret == QDialog::Accepted)
    {
        qDebug() << "Dialog accepted";
        ui->statusbar->showMessage("Accelerometer: Connected",5000);
    }

    if(ret == QDialog::Rejected)
    {
        qDebug() << "Dialog rejected";
        ui->statusbar->showMessage("Accelerometer: Disconnected. Please connect the device",10000);
    }
}



