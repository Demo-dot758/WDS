#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include "mainwindow.h"


QString AccX;
QString AccY;

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);

    QPalette palette = ui->pushButton->palette();

    palette.setColor(QPalette::Window,Qt::blue);
    palette.setColor(QPalette::WindowText,Qt::red);

    ui->pushButton->setPalette(palette);

    // Przycisk OK
    QPixmap pixmapOk("C:/Users/piotr/Desktop/Qt Creator/Pierwszy projekt/WDSapp/correct.png");
    QIcon ButtonIconOk(pixmapOk);
    ui->pushButtonOk->setIcon(ButtonIconOk);
    ui->pushButtonOk->setIconSize(QSize(15,15));

    //Przycisk Cancel
    QPixmap pixmapNo("C:/Users/piotr/Desktop/Qt Creator/Pierwszy projekt/WDSapp/remove.png");
    QIcon ButtonIconNo(pixmapNo);
    ui->pushButtonCancel->setIcon(ButtonIconNo);
    ui->pushButtonCancel->setIconSize(QSize(15,15));

    //Przycisk Search
    QPixmap pixmapSearch("C:/Users/piotr/Desktop/Qt Creator/Pierwszy projekt/WDSapp/searchicon.png");
    QIcon ButtonIconSearch(pixmapSearch);
    ui->pushButton->setIcon(ButtonIconSearch);
    ui->pushButton->setIconSize(QSize(15,15));

    //Ikona okna
    setWindowIcon(QIcon("C:/Users/piotr/Desktop/Qt Creator/Pierwszy projekt/WDSapp/connectionicon.png"));
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

    //Ustawienie połączenia z akcelerometrem
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

// Szukanie portów COM i dodawanie ich do ComboBoxa
void ConnectionDialog::on_pushButton_clicked()
{
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();
    for(int i = 0; i < devices.count(); i++) {
      qDebug() << devices.at(i).portName() << devices.at(i).description();
      ui->comboBox->addItem(devices.at(i).portName() + " " + devices.at(i).description());
    }
}

// Czytanie danych z akcelerometru
void ConnectionDialog::readFromPort()
{
    while(this->device->canReadLine()) {
        QString line = this->device->readLine();
//        qDebug() << line;

        if(line.startsWith("!"))
        {
        QStringList fields = line.split(",");

        double dAccX=fields[1].toDouble();
        double dAccY=fields[2].toDouble();

        if(dAccX-pdAccX>0.1 || dAccX-pdAccX<-0.1)
        {
            AccX=fields[1];
            qDebug() << "X: " <<AccX;
        }
        if(dAccY-pdAccY>0.1 || dAccY-pdAccY<-0.1)
        {
            AccY=fields[2];
            qDebug() << "Y: " << AccY;
        }
//        qDebug() << line.left(pos);

        pdAccX=AccX.toDouble();
        pdAccY=AccY.toDouble();
        }
    }

}

