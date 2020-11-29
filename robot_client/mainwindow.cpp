#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

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
