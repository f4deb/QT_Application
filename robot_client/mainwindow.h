#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>

#include "console.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void serialWrite(const QByteArray &data);
    Console *m_console = nullptr;

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


    void readData();

    void on_pushButton_Command_Terminal_2_clicked();
    void on_plainTextEdit_textChanged();
    void on_pushButton_Command_Terminal_3_clicked();
    void on_pushButton_Command_Terminal_4_clicked();
    void on_pushButton_Command_Terminal_5_clicked();
    void on_pushButton_Command_Terminal_6_clicked();
    void on_pushButton_Command_Terminal_7_clicked();
    void on_pushButton_Command_Terminal_8_clicked();
    void on_pushButton_Command_Terminal_9_clicked();
    void on_pushButton_Command_Terminal_10_clicked();
    void on_pushButton_Command_Terminal_11_clicked();
};
#endif // MAINWINDOW_H
