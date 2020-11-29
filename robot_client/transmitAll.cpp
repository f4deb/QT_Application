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
    serial->write(datas);

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    // On prépare le paquet à envoyer
    QString messageAEnvoyer = datas;

    out << (quint16) 0;
    out << messageAEnvoyer;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet); // On envoie le paquet


    ui->textEdit->setTextColor(QColor("red"));
    ui->textEdit->append(text);

}
