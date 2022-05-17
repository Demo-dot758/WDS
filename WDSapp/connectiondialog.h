#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QSerialPort>
namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();

    double pdAccY;
    double pdAccX;
    QString getAccX() {return AccX;}
    QString getAccY() {return AccY;}
private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButton_clicked();

    void readFromPort();
private:
    Ui::ConnectionDialog *ui;
    QSerialPort *device;
    QString AccX;
    QString AccY;
};

#endif // CONNECTIONDIALOG_H
