#include "robottitan.h"
#include "mainwindow.h"



robotTitan::robotTitan(QObject *parent) : QObject(parent)
{
    motorLeftStringValue = "00";
    motorRightStringValue = "00";
    robotCommandToSend = "";
    }

void robotTitan::SetRobotCommandToSend(QString message){
    robotCommandToSend = message;
}

QString robotTitan::getRobotCommandToSend(void){
    return robotCommandToSend;
}


 int robotTitan::motorCommand(void){
    QString s;
    s = "mw"+ motorLeftStringValue + motorRightStringValue;
    transmitAll(s);
    return 0;
}

 QString robotTitan::getEepromByte(int address){
    QString s;
    s = ROBOT_EEPROM_READ_BYTE + hex4ToString(address);
    transmitAll(s);
    return s;
 }

 QString robotTitan::setEepromByte(int address,QString s){

    s = "Ew"+ hex4ToString(address) + "-" + s;
    transmitAll(s);
    return s;
 }

 QString robotTitan::getEepromBloc(int address, int dim){
     QString s;
     s = "Eo" + hex4ToString(address) + "-" + hex4ToString(dim);
     //transmitAll(s);
     return s;
 }

 QString robotTitan::systemName(){
     SetRobotCommandToSend(ROBOT_SYSTEM_NAME_HEADER);
     transmitAll(getRobotCommandToSend());
     return 0;
  }

 QString robotTitan::reset(void){
     SetRobotCommandToSend(ROBOT_SYSTEM_RESET_HEADER);
     return getRobotCommandToSend();
 }

int robotTitan::systemUnit(){  
    SetRobotCommandToSend(ROBOT_SYSTEM_NAME_HEADER);
    transmitAll(getRobotCommandToSend());
    return 0;
 }

void robotTitan::setMotorLeft(int value){
    QString s = QString().number(value,16).right(2);
    if (value>=0 && value<=15){
        s = "0"+ s;
       }
    motorLeftStringValue = s.toUpper();
}

void robotTitan::setMotorRight(int value){
    QString s = QString().number(value,16).right(2);
    if (value>=0 && value<=15){
        s = "0"+ s;
       }
    motorRightStringValue = s.toUpper();
}

int robotTitan::getMotorleft(void){
    int value = motorLeftStringValue.toUInt();
    return value;
}

int robotTitan::getmotorRight(void){
    int value = motorRightStringValue.toUInt();
    return value;
}

QString robotTitan::motorStop(void){
    SetRobotCommandToSend(MOTOR_STOP);
    return getRobotCommandToSend();
}


void robotTitan::transmitAll(QString text){
    //qDebug() << motorLeftStringValue;
    qDebug() << text;
}

void robotTitan::receiveFromRobot(QString text){


}

QString robotTitan::hexToString(int value, int dim){
    QString s = QString().number(value,16).right(dim);
    return(s.toUpper());
}

QString robotTitan::hex2ToString(int value){
    QString s = QString().number(value,16).right(2);
    if (value>=0 && value<=15){
        s = "0"+ s;
       }
    return(s.toUpper());
}

QString robotTitan::hex4ToString (int value){
    QString s = QString().number(value,16).right(4);
    if (value>=0x100 && value<=0xFFF){
        s = "0"+ s;
       }
    if (value>=0x10 && value<=0xFF){
        s = "00"+ s;
       }
    else if (value>=0 && value<=0xF){
        s = "000"+ s;
       }
    return(s.toUpper());
}

