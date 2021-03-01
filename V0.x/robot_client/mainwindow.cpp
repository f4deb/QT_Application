#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QPainter>
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

#include "console.h"
#include "gamepadRobotClient.h"
#include "serial.h"
#include "transmitAll.h"

//Class
#include "../robot/titan/robottitan.h"


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

    etat_gamepad = 0;
    robot1 = new robotTitan;


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
    robot1->SetRobotCommandToSend(ui->Command_Terminal_1->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_2_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_2->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_plainTextEdit_textChanged()
{

}

void MainWindow::on_pushButton_Command_Terminal_3_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_3->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_4_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_4->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_5_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_5->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_6_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_6->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_7_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_7->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_8_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_8->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_9_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_9->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_10_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_10->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_Command_Terminal_11_clicked()
{
    robot1->SetRobotCommandToSend(ui->Command_Terminal_11->text());
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_Telnet_Connect_clicked()
{
    // On annonce sur la fenêtre qu'on est en train de se connecter
    statusBar()->showMessage(tr("Tentative de connexion en cours..."));
    ui->Telnet_Connect->setEnabled(false);
    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(ui->Telnet_IP->text(), ui->Telnet_Port->value()); // On se connecte au serveur demandé
}

void MainWindow::on_radioButtonTelnet_clicked()
{
       on_Telnet_Connect_clicked();
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButtonReset_clicked()
{
    QString s;
    s = robot1->reset();
    robot1->SetRobotCommandToSend(s);
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButtonStopMotor_clicked()
{
    QString s;
    s = robot1->motorStop();
    robot1->SetRobotCommandToSend(s);
    transmitAll(robot1->getRobotCommandToSend());
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_resetLeftTrackSlider_clicked()
{
    ui->VerticalSliderLeft->setValue(ui->VerticalSliderLeft->maximum() -127);
}

void MainWindow::on_resetRightTrackSlider_clicked()
{
    ui->VerticalSliderLeft->setValue(ui->VerticalSliderLeft->maximum() -127);
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
    ui->VerticalSliderLeft->setValue(ui->VerticalSliderLeft->maximum() -127);
    ui->VerticalSliderRight->setValue(ui->VerticalSliderRight->maximum() -127);
}

void MainWindow::on_radioButton_Y_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_Y_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_Y_toggled" << checked;
    }
}

void MainWindow::on_radioButton_X_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_X_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_X_toggled" << checked;
    }
}

void MainWindow::on_radioButton_B_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_B_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_B_toggled" << checked;
    }
}

void MainWindow::on_radioButton_A_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_A_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_A_toggled" << checked;
    }
}

void MainWindow::on_radioButton_Up_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_Up_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_Up_toggled" << checked;
    }
}

void MainWindow::on_radioButton_Left_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_Left_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_Left_toggled" << checked;
    }
}

void MainWindow::on_radioButton_Down_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_Down_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_Down_toggled" << checked;
    }
}

void MainWindow::on_radioButton_Right_toggled(bool checked)
{
    if (checked) {
        qDebug() << "on_radioButton_Right_toggled" << checked;
    }
    else {
        qDebug() << "on_radioButton_Right_toggled" << checked;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << "on_pushButton_5_clicked";
}

void MainWindow::on_pushButtonGamePadConnect_clicked()
{
    int result = gamepadInit();
    if (result == 0){
        ui->pushButtonGamePadConnect->setText("Connect");
        ui->pushButtonGamePadConnect->setStyleSheet("background-color: rgb(255, 208, 215);border:none;color: rgb(170, 85, 127);");
        ui->radioButtonGamepad->setChecked(false);
    }
    else {
        ui->pushButtonGamePadConnect->setStyleSheet("background-color: rgb(187, 255, 206);border:none;color: rgb(255, 0, 0);");
        ui->pushButtonGamePadConnect->setText("Disconnect");
        ui->radioButtonGamepad->setChecked(true);
    }
}

void MainWindow::on_VerticalSliderLeft_valueChanged(int value)
{
    ui->lcdNumberLeftTrackSlider->display(value);
}

void MainWindow::on_VerticalSliderRight_valueChanged(int value)
{
    ui->lcdNumberRightTrackSlider->display(value);
}

void MainWindow::on_pushButtonGamePadConnect_clicked(bool checked)
{
}

void MainWindow::on_pushButtonGamePadConnect_toggled(bool checked)
{
}

void MainWindow::on_radioButtonGamepad_toggled(bool checked)
{


}

void MainWindow::on_radioButtonGamepad_clicked()
{
    int result = gamepadInit();
    if (result == 0){
        ui->pushButtonGamePadConnect->setText("Connect");
        ui->pushButtonGamePadConnect->setStyleSheet("background-color: rgb(255, 208, 215);border:none;color: rgb(170, 85, 127);");
        ui->radioButtonGamepad->setChecked(false);
    }
    else {
        ui->pushButtonGamePadConnect->setStyleSheet("background-color: rgb(187, 255, 206);border:none;color: rgb(255, 0, 0);");
        ui->pushButtonGamePadConnect->setText("Disconnect");
        ui->radioButtonGamepad->setChecked(true);
    }
}

void MainWindow::on_pushButton_22_clicked()
{

}



// ////////////////////////////////////////////////////////////////////////////////////////////
//
//                          EEPROM
//
// //////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_EepromReadByte_clicked()
{
    QString s;
    s = robot1->getEepromByte(ui->lineEdit_RobotEepromAddress->text().toInt());
    robot1->SetRobotCommandToSend(s);
    transmitAll(robot1->getRobotCommandToSend());




}

void MainWindow::on_pushButton_EepromWriteByte_clicked()
{
    QString s;
    s = robot1->setEepromByte(ui->lineEdit_RobotEepromAddress->text().toInt(),ui->lineEdit_EepromByteHex->text());
    robot1->SetRobotCommandToSend(s);
    transmitAll(robot1->getRobotCommandToSend());
}


void MainWindow::on_pushButton_EepromReadBloc_clicked()
{
    QString s;
    s =robot1->getEepromBloc(ui->lineEdit_RobotEepromAddress->text().toInt(),ui->lineEdit_dimEeprom->text().toInt());
    robot1->SetRobotCommandToSend(s);
    transmitAll(robot1->getRobotCommandToSend());
}


void MainWindow::on_lineEdit_RobotEepromAddress_textChanged(const QString &arg1)
{
    QString s = arg1;
    int value = s.toInt();
    if (value > 65535) {
        value = 0;
    }
    s = robot1->hexToString(value,4);
    ui->lineEdit_RobotEepromAddressHex->setText(s);
    ui->lineEdit_RobotEepromStopAddress->setText(QString::number(value + ui->lineEdit_dimEeprom->text().toInt())) ;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_RobotEepromAddressHex_textChanged(const QString &arg1)
{
    QString s = arg1;
    bool ok = false;
    int value = s.toInt(&ok,16);
    if (value > 0xFFFF) {
        value = 0;
    }
    ui->lineEdit_RobotEepromAddress->setText(QString::number(value));
}

void MainWindow::on_lineEdit_RobotEepromStopAddress_textChanged(const QString &arg1)
{
    bool ok;
    QString s = arg1;
    int value = s.toInt();
    if (value > 65535) {
        value = 0;
    }
    s = robot1->hexToString(value,4);
    ui->lineEdit_RobotEepromStopAddressHex->setText(s);
    ui->lineEdit_dimEeprom->setText(QString::number(value- ui->lineEdit_RobotEepromAddress->text().toInt()) );
}

void MainWindow::on_lineEdit_RobotEepromStopAddressHex_textChanged(const QString &arg1)
{
    QString s = arg1;
    bool ok = false;
    int value = s.toInt(&ok,16);
    if (value > 0xFFFF) {
        value = 0;
    }
    ui->lineEdit_RobotEepromStopAddress->setText(QString::number(value));
}

void MainWindow::on_lineEdit_dimEeprom_textChanged(const QString &arg1)
{
    QString s = arg1;
    int value = s.toInt();
    if (value > 65535) {
        value = 0;
    }
    s = robot1->hexToString(value,4);
    ui->lineEdit_dimEepromHex->setText(s);
    ui->lineEdit_RobotEepromStopAddress->setText(QString::number(value + ui->lineEdit_RobotEepromAddress->text().toInt()) );
}

void MainWindow::on_lineEdit_dimEepromHex_textChanged(const QString &arg1)
{
    QString s = arg1;
    bool ok = false;
    int value = s.toInt(&ok,16);
    if (value > 0xFFFF) {
        value = 0;
    }
    ui->lineEdit_dimEeprom->setText(QString::number(value));
}

void MainWindow::on_lineEdit_EepromByte_textChanged(const QString &arg1)
{
    QString s = arg1;
    int value = s.toInt();
    if (value > 65535) {
        value = 0;
    }
    s = robot1->hex2ToString(value);
    ui->lineEdit_EepromByteHex->setText(s);
}

void MainWindow::on_lineEdit_EepromByteHex_textChanged(const QString &arg1)
{
    QString s = arg1;
    bool ok = false;
    int value = s.toInt(&ok,16);
    if (value > 0xFF) {
        value = 0;
    }
    ui->lineEdit_EepromByte->setText(QString::number(value));
}


void MainWindow::on_pushButton_23_clicked()
{

}





void MainWindow::on_pushButton_EepromReadByte_clicked(bool checked)
{

}


