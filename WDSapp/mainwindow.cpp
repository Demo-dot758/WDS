#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectiondialog.h"
#include "waterwidget.h"
#include <QTimer>
#include <QDebug>
#include <QDialog>

//Konstruktor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectionDialog dialog;  //Okienko dialog po wcisnieciu "Connection"

    //Timer do zmiany przycisku START/STOP
    myTimer = new QTimer(this);
    myTimer->setInterval(500);
    myTimer->setSingleShot(false);
    connect(myTimer, SIGNAL(timeout()),this, SLOT(timerslot()));
    myTimer->start();


    //Timer do odświeżania wartości pobranych z akcelerometru
    labelTimer = new QTimer(this);
    connect(labelTimer,SIGNAL(timeout()),this,SLOT(LabelTimerSlot()));

//    connect(&dialog,SIGNAL(timeout()),this,SLOT(Label_show_values()));


    //Ikonka przycisku "Connection"
    QPixmap pixmapConnection("C:/Users/piotr/Desktop/Qt Creator/Pierwszy projekt/WDSapp/connectionicon.png");
    QIcon connectionIcon(pixmapConnection);
    ui->actionConnection->setIcon(connectionIcon);

    //Ikonka aplikacji
    setWindowIcon(QIcon("C:/Users/piotr/Desktop/Qt Creator/Pierwszy projekt/WDSapp/waterglassicon2.png"));

    ui->pushButtonStartStop->setStyleSheet("background-color: green;color:white");

    ui->pushButtonReset->setStyleSheet("background-color: red;color:white");

//    WaterWidget * waterwidget = new WaterWidget(this);

    ui->labelX->setAutoFillBackground(true);
    ui->labelX->setStyleSheet("QLabel{background: white;color:black}");

    ui->labelY->setAutoFillBackground(true);
    ui->labelY->setStyleSheet("QLabel{background: white;color:black}");




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


void MainWindow::LabelTimerSlot()
{
    Label_read_values();
}

// Wyswietlanie pomiarów z akcelerometru w interfejsie, nie działa
void MainWindow::Label_read_values()
{
    ConnectionDialog dialog;
    ui->labelX->setText(AccX);
    ui->labelY->setText(AccY);
}

// Przycisk Reset
void MainWindow::on_pushButtonReset_clicked()
{
    ui->statusbar->showMessage("Restart",2000);
}

// Przycisk Start/Stop
void MainWindow::on_pushButtonStartStop_clicked()
{
    if ( this->myTimer->isActive() == true ) {
            this->labelTimer->start(50);
            this->myTimer->stop();
            ui->pushButtonStartStop->setText("Stop");
            ui->pushButtonStartStop->setStyleSheet("background-color: red;color:white");
            ui->statusbar->showMessage("Appliaction started",2000);
            setStartStop(true);
        } else {
            this->labelTimer->stop();
            this->myTimer->start(500);
            ui->pushButtonStartStop->setText("Start");
            ui->pushButtonStartStop->setStyleSheet("background-color: green;color:white");
            ui->statusbar->showMessage("Appliaction stopped",2000);
            setStartStop(false);
        }
}


// Okienko połączenia z akcelerometrem, wyświetlania zatwierdzenia lub rezygnacji z połączenia na dolnym pasku aplikacji
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



