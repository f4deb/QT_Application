#include "mainwindow.h"

#include <QtWidgets>
#include <QThread>


void MainWindow::on_actionA_propos_triggered()
{
    QMessageBox::information(this, "A Propos", "Interface Titan Begin Mai 2020 / Last Update V0.11 "
                                               "by F4DEB Novembre 2020");
    char text[30] = "hello coucou";
        serial->write(text);
}
