#include "mainwindow.h"

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    QGamepadManager* gamepad_manager = QGamepadManager::instance();
    QList<int> gamepads;
    int i = 0;
    while (i < 10)
    {
        a.processEvents();


        qInfo() << "get connected gamepads iteration : " << i;
        gamepads = gamepad_manager->connectedGamepads();
        if(!gamepads.isEmpty())
        {
            i = 10;
        }
        i++;
    }
    qInfo() << "connected gamepads : " << gamepads.size();
*/

    return a.exec();
}
