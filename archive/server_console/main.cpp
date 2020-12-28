#include <QCoreApplication>
#include <iostream>

#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    title();
    initServer();
    initSerial();

    cin.get();
    return a.exec();
}

void title (void){
    cout << "Qt Version: " << QT_VERSION_STR << endl;
    cout << "Robot Server, F4DEB, Decembre 2020\n";
}

void initServer(){

}

void initSerial(){

}
