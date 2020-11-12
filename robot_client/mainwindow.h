#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>

#include "terminal.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Terminal *terminal;
    int etat_serial_port;

    QSerialPort *serial;
    void openSerialPort();
    void closeSerialPort();

private:
    Ui::MainWindow *ui;

private:
    void initSerialPort();
    void serialInit();
    void fillPortsParameters();
    void fillPortsInfo();



public slots:


private slots:
    void on_pushButtonQuit_clicked();
    void on_buttonQuitter_clicked();
    void on_actionQuitter_changed();
    void on_actionQuitter_toggled(bool arg1);
    void on_actionQuitter_triggered();
    void on_actionA_propos_triggered();
    void on_Serial_Connect_clicked();
    void on_Serial_Baudrate_currentTextChanged(const QString &arg1);
    void on_Serial_Port_activated(const QString &arg1);
    void on_Serial_Port_currentIndexChanged(const QString &arg1);
    void on_pushButton_Command_Terminal_1_clicked();
};
#endif // MAINWINDOW_H
