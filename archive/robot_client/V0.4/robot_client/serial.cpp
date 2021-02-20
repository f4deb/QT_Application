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
    ui->Serial_Baudrate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->Serial_Baudrate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->Serial_Baudrate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->Serial_Baudrate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->Serial_Baudrate->setCurrentIndex(3);

    ui->Serial_Data_Bits->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->Serial_Data_Bits->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->Serial_Data_Bits->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->Serial_Data_Bits->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->Serial_Data_Bits->setCurrentIndex(3);

    ui->Serial_Parity->addItem(tr("None"), QSerialPort::NoParity);
    ui->Serial_Parity->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->Serial_Parity->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->Serial_Parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->Serial_Parity->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->Serial_Stop_Bits->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->Serial_Stop_Bits->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->Serial_Stop_Bits->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    ui->Serial_Flow_Control->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->Serial_Flow_Control->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->Serial_Flow_Control->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
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

    if (etat_serial_port == 1) {
        serial->close();
        etat_serial_port = 0;

        ui->Serial_Connect->setText("Connect");
        statusBar()->showMessage(tr("Serial Port Disconnected"));
        ui->Serial_Connect->setStyleSheet("color: rgb(170, 85, 127);border:none;background-color: rgb(255, 208, 215);");
        return;
    }

    serial->setPortName(ui->Serial_Port->currentText());
    //serial->setPortName(serialPortInfoListBox->currentText());
    serial->setBaudRate(static_cast<QSerialPort::BaudRate>(ui->Serial_Baudrate->itemData(ui->Serial_Baudrate->currentIndex()).toInt()));
    serial->setDataBits(static_cast<QSerialPort::DataBits>(ui->Serial_Data_Bits->itemData(ui->Serial_Data_Bits->currentIndex()).toInt()));
    serial->setParity(static_cast<QSerialPort::Parity>(ui->Serial_Parity->itemData(ui->Serial_Parity->currentIndex()).toInt()));
    serial->setStopBits(static_cast<QSerialPort::StopBits>(ui->Serial_Stop_Bits->itemData(ui->Serial_Stop_Bits->currentIndex()).toInt()));
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(ui->Serial_Flow_Control->itemData(ui->Serial_Flow_Control->currentIndex()).toInt()));

    if (serial->open(QIODevice::ReadWrite)) {
        ui->Serial_Connect->setText("Disconnect");
        statusBar()->showMessage(tr("Serial Port Connected"));
        QObject::connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
        etat_serial_port = 1;
        ui->Serial_Connect->setStyleSheet("background-color: rgb(187, 255, 206);border:none;color: rgb(255, 0, 0);");
    } else {
        ui->Serial_Connect->setText("Connect");
        QObject::disconnect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
        statusBar()->showMessage(tr("Serial Port error"));
        etat_serial_port = -1;
        ui->Serial_Connect->setStyleSheet("color: rgb(170, 85, 127);border:none;background-color: rgb(255, 208, 215);");
    }
}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
}

void MainWindow::initSerialPort(){

}

void MainWindow::serialWrite(const QByteArray &data){
    const QByteArray datas="455";
    serial->write(datas);
}

void MainWindow::readData(){
    //while (serial->waitForReadyRead(100));
    QByteArray datass = serial->readAll();

    ui->textEdit->setTextColor(QColor("green"));
    ui->textEdit->insertPlainText (datass);
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
}
