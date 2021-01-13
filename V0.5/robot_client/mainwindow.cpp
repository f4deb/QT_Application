#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QTableWidget>
#include <QtGamepad>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QWidget>

#include <QtGamepad/QGamepad>

#include <QtSerialPort/QSerialPortInfo>

#include "./Qt-custom-gauge-widget-master/source/qcgaugewidget.h"
#include "./qcustomplot/qcustomplot.h"

#include "serial.h"
#include "console.h"
#include "transmitAll.h"

extern int etat_serial_port;
extern int etat_serveur_port;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_console(new Console)
{
    ui->setupUi(this);

    m_console->setEnabled(false);

    serialInit();
    serverInit();
    //gamepadInit();





    QLoggingCategory::setFilterRules(QStringLiteral("qt.gamepad.debug=true"));
    QGamepadManager* gamepad_manager = QGamepadManager::instance();
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    int i = 0;
    while (i < 10)
    {
        QCoreApplication::processEvents();
        gamepads = gamepad_manager->connectedGamepads();
        if(!gamepads.isEmpty())
        {
            i = 10;
        }
        i++;
    }










    if (gamepads.isEmpty()) {
        qDebug() << "Did not find any connected gamepad";
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);

    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [](double value){
        qDebug() << "Left X" << value;
    });
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [](double value){
        qDebug() << "Left Y" << value;
    });
    connect(m_gamepad, &QGamepad::axisRightXChanged, this, [](double value){
        qDebug() << "Right X" << value;
    });
    connect(m_gamepad, &QGamepad::axisRightYChanged, this, [](double value){
        qDebug() << "Right Y" << value;
    });
    connect(m_gamepad, &QGamepad::buttonAChanged, this, [](bool pressed){
        qDebug() << "Button A" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonBChanged, this, [](bool pressed){
        qDebug() << "Button B" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [](bool pressed){
        qDebug() << "Button X" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [](bool pressed){
        qDebug() << "Button Y" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [](bool pressed){
        qDebug() << "Button L1" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [](bool pressed){
        qDebug() << "Button R1" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [](double value){
        qDebug() << "Button L2: " << value;
    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [](double value){
        qDebug() << "Button R2: " << value;
    });
    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, [](bool pressed){
        qDebug() << "Button Select" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonStartChanged, this, [](bool pressed){
        qDebug() << "Button Start" << pressed;
    });
    connect(m_gamepad, &QGamepad::buttonGuideChanged, this, [](bool pressed){
        qDebug() << "Button Guide" << pressed;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonQuit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_buttonQuitter_clicked()
{
    QMessageBox::information(this, "A Propos", "fofo");
}

void MainWindow::on_actionQuitter_changed()
{
    QMessageBox::information(this, "A Propos", "toto");
}

void MainWindow::on_actionQuitter_toggled(bool arg1)
{
        QMessageBox::information(this, "A Propos", "momo");
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_Command_Terminal_1_clicked()
{
    transmitAll(ui->Command_Terminal_1->text());
}

void MainWindow::on_pushButton_Command_Terminal_2_clicked()
{
    transmitAll(ui->Command_Terminal_2->text());
}

void MainWindow::on_plainTextEdit_textChanged()
{

}

void MainWindow::on_pushButton_Command_Terminal_3_clicked()
{
    transmitAll(ui->Command_Terminal_3->text());
}

void MainWindow::on_pushButton_Command_Terminal_4_clicked()
{
    transmitAll(ui->Command_Terminal_4->text());
}

void MainWindow::on_pushButton_Command_Terminal_5_clicked()
{
   transmitAll(ui->Command_Terminal_5->text());
}

void MainWindow::on_pushButton_Command_Terminal_6_clicked()
{
    transmitAll(ui->Command_Terminal_6->text());
}

void MainWindow::on_pushButton_Command_Terminal_7_clicked()
{
    transmitAll(ui->Command_Terminal_7->text());
}

void MainWindow::on_pushButton_Command_Terminal_8_clicked()
{
    transmitAll(ui->Command_Terminal_8->text());
}

void MainWindow::on_pushButton_Command_Terminal_9_clicked()
{
    transmitAll(ui->Command_Terminal_9->text());
}

void MainWindow::on_pushButton_Command_Terminal_10_clicked()
{
   transmitAll(ui->Command_Terminal_10->text());
}

void MainWindow::on_pushButton_Command_Terminal_11_clicked()
{
   transmitAll(ui->Command_Terminal_11->text());
}

void MainWindow::on_Telnet_Connect_clicked()
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    statusBar()->showMessage(tr("Tentative de connexion en cours..."));
    ui->Telnet_Connect->setEnabled(false);
    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(ui->Telnet_IP->text(), ui->Telnet_Port->value()); // On se connecte au serveur demandé
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButtonReset_clicked()
{
    transmitAll("SR");
}

void MainWindow::on_pushButtonStopMotor_clicked()
{
    transmitAll("Mc");
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_resetLeftTrackSlider_clicked()
{
    ui->leftTrackSlider->setValue(ui->leftTrackSlider->maximum() -127);
}

void MainWindow::on_resetRightTrackSlider_clicked()
{
    ui->rightTrackSlider->setValue(ui->rightTrackSlider->maximum() -127);
}

void MainWindow::on_leftTrackSlider_valueChanged(int value)
{
    ui->lcdNumberLeftTrackSlider->display(value);
}

void MainWindow::on_rightTrackSlider_valueChanged(int value)
{
    ui->lcdNumberRightTrackSlider->display(value);
}

void MainWindow::on_pushButton_StropTrack_clicked()
{
    ui->leftTrackSlider->setValue(ui->leftTrackSlider->maximum() -127);
    ui->rightTrackSlider->setValue(ui->rightTrackSlider->maximum() -127);
}
