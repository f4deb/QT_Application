#include <QScrollBar>
#include <QtCore/QDebug>

#include "mainwindow.h"
#include "serial.h"
#include "ui_mainwindow.h"

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

//int etat_serial_port;


void MainWindow::on_Serial_Connect_clicked()
{    
    openSerialPort();
}

void MainWindow::on_Serial_Baudrate_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_Serial_Port_activated(const QString &arg1)
{

}

void MainWindow::on_Serial_Port_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::serialInit()
{
    serial = new QSerialPort;
    fillPortsParameters();
    fillPortsInfo();
    etat_serial_port = 0;

}

void MainWindow::fillPortsParameters()
{

}

void MainWindow::fillPortsInfo()
{
    ui->Serial_Port->clear();

    QString description;
    QString manufacturer;
    QString serialNumber;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) :blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->Serial_Port->addItem(list.first(), list);
    }
}

void MainWindow::openSerialPort(){

    int defineParity=0;
    if (ui->Serial_Parity->currentText() == "NoParity") defineParity=0;
    else if (ui->Serial_Parity->currentText() == "EvenParity") defineParity=2;
    else if (ui->Serial_Parity->currentText() == "OddParity") defineParity=3;
    else if (ui->Serial_Parity->currentText() == "SpaceParity") defineParity=4;
    else if (ui->Serial_Parity->currentText() == "MarkParity") defineParity=5;
    else defineParity=-1;

    int defineStopBit=0;
    if (ui->Serial_Stop_Bits->currentText() == "OneStop") defineStopBit=1;
    else if (ui->Serial_Stop_Bits->currentText() == "OneAndHalfStop") defineStopBit=3;
    else if (ui->Serial_Stop_Bits->currentText() == "TwoStop") defineStopBit=2;
    else defineStopBit=-1;

    if (etat_serial_port == 1) {
        serial->close();
        etat_serial_port = 0;
        ui->Serial_Connect->setText("Connect");
        statusBar()->showMessage(tr("Serial Port Disconnected"));
        return;
    }
    serial->setPortName(ui->Serial_Port->currentText());
    serial->setBaudRate(ui->Serial_Baudrate->currentText().toInt());
    serial->setDataBits(static_cast<QSerialPort::DataBits>(ui->Serial_Data_Bits->currentText().toUInt()));
    serial->setParity(static_cast<QSerialPort::Parity>(defineParity));
    serial->setStopBits(static_cast<QSerialPort::StopBits>(defineStopBit));
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(1)); //pas de controle de flux

    if (serial->open(QIODevice::ReadWrite)) {
        char car[10]="ouvert";
        serial->write(car);
        ui->Serial_Connect->setText("Disconnect");
        //statusBar()->showMessage(tr("Serial Port Connected"));
        QObject::connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
        etat_serial_port = 1;
    } else {
        ui->Serial_Connect->setText("Connect");
        QObject::disconnect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
        //statusBar()->showMessage(tr("Serial Port error"));
        etat_serial_port = -1;
    }
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
}

void MainWindow::initSerialPort(){

       //QMessageBox::information(this,"debug",QString("%1").arg(ui->Serial_Data_Bits->currentText()));
}

void MainWindow::serialWrite(const QByteArray &data){
    const QByteArray datas="455";
    serial->write(datas);
}

void MainWindow::readData(){
    while (serial->waitForReadyRead(10));
    QByteArray datass = serial->readAll();
    //envoyerATous(datass);
}
