#include "mainwindow.h"

#include <QtWidgets>
#include <QThread>


void MainWindow::on_actionA_propos_triggered()
{
    QMessageBox::information(this, "A Propos", "Robot Client Mai 2020 / Last Update V0.60 "
                                               "by F4DEB Fev 2021");
}
