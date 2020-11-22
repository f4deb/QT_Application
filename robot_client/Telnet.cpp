#include <QtCore/QDebug>

#include "mainwindow.h"
#include "Telnet.h"
#include "ui_mainwindow.h"


void MainWindow::serverInit(){
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));

    etat_serveur_port =0;

}

// On a reçu un paquet (ou un sous-paquet)
void MainWindow::donneesRecues()
{
    /* Même principe que lorsque le serveur reçoit un paquet :
    On essaie de récupérer la taille du message
    Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se basant sur la taille annoncée tailleMessage)
    */
    QDataStream in(socket);

    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;

        in >> tailleMessage;
    }

    if (socket->bytesAvailable() < tailleMessage)
        return;


    // Si on arrive jusqu'à cette ligne, on peut récupérer le message entier
    QString messageRecu;
    in >> messageRecu;

    // On affiche le message sur la zone de Chat
    //listeMessages->append(messageRecu);
    ui->plainTextEdit->insertPlainText("Data server OK");

    // On remet la taille du message à 0 pour pouvoir recevoir de futurs messages
    tailleMessage = 0;
}

// Ce slot est appelé lorsque la connexion au serveur a réussi
void MainWindow::connecte()
{



    if (etat_serveur_port == 0) {
        statusBar()->showMessage(tr("Server Port Disconnected"));
        etat_serveur_port = 1;
        return;
    }
    else {
        statusBar()->showMessage(tr("Server Port connected"));
        etat_serveur_port = 0;
        return;
    }


    //statusBar()->showMessage("Connexion réussie");
    //ui->Telnet_Connect->setEnabled(true);
    //ui->Telnet_Connect->setStyleSheet("background-color: rgb(0, 0, 255);color: rgb(255, 0, 0);");
    //etat_serveur_port = 1;
}

// Ce slot est appelé lorsqu'on est déconnecté du serveur
void MainWindow::deconnecte()
{
    statusBar()->showMessage("Déconnecté du serveur");
    ui->Telnet_Connect->setStyleSheet("background-color: rgb(0, 255, 0);color: rgb(255, 0, 0);");
    etat_serveur_port = 0;
}

// Ce slot est appelé lorsqu'il y a une erreur
void MainWindow::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
        case QAbstractSocket::HostNotFoundError:
            statusBar()->showMessage("ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port.");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            statusBar()->showMessage("ERREUR : le serveur a refusé la connexion. Vérifiez si le \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port.");
            break;
        case QAbstractSocket::RemoteHostClosedError:
            statusBar()->showMessage("ERREUR : le serveur a coupé la connexion.");
            break;
        default:
            statusBar()->showMessage(("ERREUR : ") + socket->errorString());
    }

    //boutonConnexion->setEnabled(true);
}
