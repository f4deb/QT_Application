#ifndef ROBOTTITAN_H
#define ROBOTTITAN_H

#include <QObject>

#define ACKNOWLEDGE "a"
#define ROBOT_SYSTEM_RESET_HEADER "SR"
#define ROBOT_SYSTEM_NAME_HEADER "SN"
#define ROBOT_EEPROM_READ_BYTE "Er"
#define ROBOT_EEPROM_READ_BLOC "Eo"

#define MOTOR_STOP "mc"
#define MOTOR_WRITE "mw"


class robotTitan : public QObject
{
    Q_OBJECT
public:
    explicit robotTitan(QObject *parent = nullptr);

    //Command Robot
    QString systemName(void);
    int systemUnit (void);
    QString motorCommand (void);
    QString reset (void);

    void setMotorLeft(int);
    void setMotorRight(int);
    int getMotorleft(void);
    int getmotorRight(void);
    QString motorStop(void);
    bool getMotorAcknowledge(void);
    void setMotorAcknowledge(bool);

    QString getRobotCommandToSend(void);
    void SetRobotCommandToSend(QString);

    QString getEepromByte(int);
    QString setEepromByte(int,QString);
    QString getEepromBloc(int,int);
    void setEepromBloc(int,int);

    QString hexToString(int,int);
    QString hex2ToString(int);
    QString hex4ToString(int);

    void receiveFromRobot(QString);

private:
    bool motorAcknowledge;
    QString motorLeftStringValue;
    QString motorRightStringValue;
    QString robotCommandToSend;
    QString stringToConvert;


    void transmitAll(QString text);



signals:


};
#endif // ROBOTTITAN_H
