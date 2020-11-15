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

extern int etat_serial_port;
extern int etat_serveur_port;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_console(new Console)
{
    ui->setupUi(this);

    m_console->setEnabled(false);
    //setCentralWidget(m_console);

    //m_console->putData(data,0)
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


void MainWindow::on_pushButton_Command_Terminal_1_clicked()
{

    QByteArray datas =  ui->Command_Terminal_1->text().toUtf8();
    serial->write(datas);

    ui->plainTextEdit->insertPlainText(ui->Command_Terminal_1->text());
}

void MainWindow::on_pushButton_Command_Terminal_2_clicked()
{
    const QByteArray text;
    serialWrite(text);

    QByteArray datas = "BORDEL";
    serial->write(datas);

}

void MainWindow::on_plainTextEdit_textChanged()
{

}
