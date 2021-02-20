#include "transmitAll.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtWidgets>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


void MainWindow::transmitAll(QString text){

    QByteArray datas = text.toUtf8();
    if (serial->isOpen()){

        serial->write(datas);
    }

    if (socket->isOpen()){
        QByteArray paquet;
        QDataStream out(&paquet, QIODevice::WriteOnly);

        // On prépare le paquet à envoyer
        QString messageAEnvoyer = datas;

        out << (quint16) 0;
        out << messageAEnvoyer;
        out.device()->seek(0);
        out << (quint16) (paquet.size() - sizeof(quint16));

        socket->write(paquet); // On envoie le paquet
    }

    ui->textEdit->setTextColor(QColor("red"));
    ui->textEdit->append(text+"\n");
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    qDebug() << text;
}

void MainWindow::receiveAll(QString text){
    ui->textEdit->setTextColor(QColor("green"));
    ui->textEdit->insertPlainText (text);
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    robot1->receiveFromRobot(text);

    qDebug() << text;

    if ( text.contains(QString (ACKNOWLEDGE) + ROBOT_EEPROM_READ_BYTE)) {
        ui->lineEdit_EepromByteHex->setText(text.remove(QString (ACKNOWLEDGE) + ROBOT_EEPROM_READ_BYTE));
    }
    if ( text.contains(QString (ACKNOWLEDGE) + ROBOT_EEPROM_READ_BLOC)) {
        ui->textBrowser->setText(text.remove(QString (ACKNOWLEDGE) + ROBOT_EEPROM_READ_BLOC));
    }
}
