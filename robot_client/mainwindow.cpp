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
#include "terminal.h"


extern int etat_serial_port;
extern int etat_serveur_port;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialInit();

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

