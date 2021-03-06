#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtNetwork>
#include <QtSerialPort/QSerialPortInfo>

#include <QtGamepad/QGamepad>

#include <QDebug>
#include <QLoggingCategory>

#include "console.h"

//Class

#include "../robot/titan/robottitan.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Serial Port
    int etat_serial_port;
    QSerialPort *serial;
    void openSerialPort();
    void closeSerialPort();

    //Server
    int etat_serveur_port;
    int etat_gamepad;

    robotTitan *robot1;


private:
    Ui::MainWindow *ui;

private:
    //GAMEPAD
    QGamepad *m_gamepad;

    //TERMINAL
    Console *m_console = nullptr;

    // Port Serie
    void initSerialPort();
    void serialInit();
    void fillPortsParameters();
    void fillPortsInfo();
    void serialWrite(const QByteArray &data);


    // Server

    void serverInit();

    QTcpSocket *socket; // Représente le serveur
    quint16 tailleMessage;

//    void transmitAll(QString text);

    // Gamepad
    int gamepadInit();
    const QList<int> gamepadStatus();
    void gamepadClose(void);
    void padBouttonL2(double value);
    void padBouttonR2(double value);
    void padBouttonHorizontalLeft(double value);
    void padBouttonVerticalLeft(double value);
    void padBouttonHorizontalRight(double value);
    void padBouttonVerticalRight(double value);
    void radioButtonA(bool status);
    void radioButtonB(bool status);
    void radioButtonX(bool status);
    void radioButtonY(bool status);
    void radioButtonL1(bool status);
    void radioButtonR1(bool status);
    void radioButtonSelect(bool status);
    void radioButtonStart(bool status);
    void radioButtonLeft(bool status);
    void radioButtonRight(bool status);
    void radioButtonUp(bool status);
    void radioButtonDown(bool status);


public slots:

    void transmitAll(QString text);
    int receiveAll(QString text);


private slots:

    void donneesRecues();
    void connecte();
    void deconnecte();
    void erreurSocket(QAbstractSocket::SocketError erreur);


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
    void on_Telnet_Connect_clicked();
    void on_pushButton_clicked();
    void on_pushButtonReset_clicked();
    void on_pushButtonStopMotor_clicked();
    void on_pushButton_2_clicked();
    void on_resetLeftTrackSlider_clicked();
    void on_resetRightTrackSlider_clicked();
    void on_leftTrackSlider_valueChanged(int value);
    void on_rightTrackSlider_valueChanged(int value);
    void on_pushButton_StropTrack_clicked();
    void on_radioButton_Y_toggled(bool checked);
    void on_radioButton_X_toggled(bool checked);
    void on_radioButton_B_toggled(bool checked);
    void on_radioButton_A_toggled(bool checked);
    void on_radioButton_Up_toggled(bool checked);
    void on_radioButton_Left_toggled(bool checked);
    void on_radioButton_Down_toggled(bool checked);
    void on_radioButton_Right_toggled(bool checked);
    void on_pushButton_5_clicked();
    void on_pushButtonGamePadConnect_clicked();
    void on_VerticalSliderLeft_valueChanged(int value);
    void on_VerticalSliderRight_valueChanged(int value);
    void on_pushButtonGamePadConnect_clicked(bool checked);
    void on_pushButtonGamePadConnect_toggled(bool checked);
    void on_radioButtonGamepad_toggled(bool checked);
    void on_radioButtonGamepad_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_EepromReadByte_clicked();
    void on_lineEdit_RobotEepromAddress_textChanged(const QString &arg1);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_RobotEepromAddressHex_textChanged(const QString &arg1);
    void on_pushButton_EepromWriteByte_clicked();
    void on_lineEdit_dimEeprom_textChanged(const QString &arg1);
    void on_lineEdit_dimEepromHex_textChanged(const QString &arg1);
    void on_lineEdit_RobotEepromStopAddress_textChanged(const QString &arg1);
    void on_lineEdit_RobotEepromStopAddressHex_textChanged(const QString &arg1);
    void on_lineEdit_EepromByteHex_textChanged(const QString &arg1);
    void on_lineEdit_EepromByte_textChanged(const QString &arg1);
    void on_pushButton_23_clicked();
    void on_pushButton_EepromReadBloc_clicked();
    void on_pushButton_EepromReadByte_clicked(bool checked);
    void on_radioButtonTelnet_clicked();
};
#endif // MAINWINDOW_H
