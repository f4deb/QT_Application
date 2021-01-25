#include "mainwindow.h"
#include "ui_mainwindow.h"

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
