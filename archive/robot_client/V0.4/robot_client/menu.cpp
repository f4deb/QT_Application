#include "mainwindow.h"

#include <QtWidgets>
#include <QThread>


void MainWindow::on_actionA_propos_triggered()
{
    QMessageBox::information(this, "A Propos", "Robot Client Mai 2020 / Last Update V0.20 "
                                               "by F4DEB January 2021");
}
