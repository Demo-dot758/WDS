#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include "mainwindow.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_pushButtonOk_clicked()
{
    if(ui->comboBox->count() == 0) {
      qDebug("Nie wykryto żadnych urządzeń!");
      return;
    }

    QString portName = ui->comboBox->currentText().split("\t").first();
    this->device->setPortName("COM8");

    // Otwórz i skonfiguruj port:a
    if(!device->isOpen()) {
    if(device->open(QSerialPort::ReadWrite)) {
      this->device->setBaudRate(QSerialPort::Baud115200);
      this->device->setDataBits(QSerialPort::Data8);
      this->device->setParity(QSerialPort::NoParity);
      this->device->setStopBits(QSerialPort::OneStop);
      this->device->setFlowControl(QSerialPort::NoFlowControl);

      connect(this->device, SIGNAL(readyRead()),this, SLOT(readFromPort()));
      qDebug("Otwarto port szeregowy.");
    } else {
      qDebug("Otwarcie porty szeregowego się nie powiodło!");
    }
    } else{
      qDebug("Port już jest otwarty!");
    }
    accept();
}


void ConnectionDialog::on_pushButtonCancel_clicked()
{

    if(this->device->isOpen()) {
      this->device->close();
      qDebug("Zamknięto połączenie.");
    } else {
      qDebug("Port nie jest otwarty!");
      return;
    }
    reject();
}


void ConnectionDialog::on_pushButton_clicked()
{
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    for(int i = 0; i < devices.count(); i++) {
      qDebug() << devices.at(i).portName() << devices.at(i).description();
      ui->comboBox->addItem(devices.at(i).portName() + " " + devices.at(i).description());
    }
}

void ConnectionDialog::readFromPort()
{
    while(this->device->canReadLine()) {
        QString line = this->device->readLine();
//        qDebug() << line;

        QStringList fields = line.split(",");
        AccX=fields[0];
        AccY=fields[1];
        qDebug() << AccX;
        qDebug() << AccY;
//        qDebug() << line.left(pos);
    }

}

