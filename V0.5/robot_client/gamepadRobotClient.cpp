#include <QtCore/QDebug>

#include <QPainter>
#include <QPushButton>
#include <QTableWidget>
#include <QtGamepad>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QWidget>
#include <QtGamepad/QGamepad>

#include "mainwindow.h"
#include "gamepadRobotClient.h"
#include "ui_mainwindow.h"


void MainWindow::gamepadInit(){
    QLoggingCategory::setFilterRules(QStringLiteral("qt.gamepad.debug=true"));
    QGamepadManager* gamepad_manager = QGamepadManager::instance();
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    int i = 0;
    while (i < 100)
    {
        QCoreApplication::processEvents();
        gamepads = gamepad_manager->connectedGamepads();
        if(!gamepads.isEmpty())
        {
            i = 100;
        }
        i++;
    }

    if (gamepads.isEmpty()) {
        qDebug() << "Did not find any connected gamepad";
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);

    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [this](double value){
        qDebug() << "Left X" << value;
        padBouttonLeftX(value);
    });
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [this](double value){
        value = -value;
        qDebug() << "Left Y" << value;
        padBouttonLeftY(value);
    });
    connect(m_gamepad, &QGamepad::axisRightXChanged, this, [this](double value){
        qDebug() << "Right X" << value;
        padBouttonRightX(value);
    });
    connect(m_gamepad, &QGamepad::axisRightYChanged, this, [this](double value){
        value = -value;
        qDebug() << "Right Y" << value;
        padBouttonRightY(value);
    });
    connect(m_gamepad, &QGamepad::buttonAChanged, this, [this](bool pressed){
        qDebug() << "Button A" << pressed;
        radioButtonA(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonBChanged, this, [this](bool pressed){
        qDebug() << "Button B" << pressed;
        radioButtonB(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [this](bool pressed){
        qDebug() << "Button X" << pressed;
        radioButtonX(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [this](bool pressed){
        qDebug() << "Button Y" << pressed;
        radioButtonY(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [this](bool pressed){
        qDebug() << "Button L1" << pressed;
        radioButtonL1(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [this](bool pressed){
        qDebug() << "Button R1" << pressed;
        radioButtonR1(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [this](double value){
        qDebug() << "Button L2: " << value;
        padBouttonL2(value);
    });
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, [this](double value){
        qDebug() << "Button R2: " << value;
        padBouttonR2(value);
    });
    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, [this](bool pressed){
        qDebug() << "Button Select" << pressed;
        radioButtonSelect(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonStartChanged, this, [this](bool pressed){
        qDebug() << "Button Start" << pressed;
        radioButtonStart(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonLeftChanged, this, [this](bool pressed){
        qDebug() << "Button Left" << pressed;
        radioButtonLeft(pressed);
    });

    connect(m_gamepad, &QGamepad::buttonRightChanged, this, [this](bool pressed){
        qDebug() << "Button Right" << pressed;
        radioButtonRight(pressed);
    });

    connect(m_gamepad, &QGamepad::buttonUpChanged, this, [this](bool pressed){
        qDebug() << "Button up" << pressed;
        radioButtonUp(pressed);
    });

    connect(m_gamepad, &QGamepad::buttonDownChanged, this, [this](bool pressed){
        qDebug() << "Button Down" << pressed;
        radioButtonDown(pressed);
    });
}

void MainWindow::padBouttonL2(double value){
    int valueByte= (value * 100);
    ui->progressBarLeft->setValue(valueByte);
}

void MainWindow::padBouttonR2(double value){
    int valueByte= (value * 100);
    ui->progressBarRight->setValue(valueByte);
}

void MainWindow::radioButtonA(bool status){
    ui->radioButtonA->setChecked(status);
}

void MainWindow::radioButtonB(bool status){
    ui->radioButtonB->setChecked(status);
}

void MainWindow::radioButtonX(bool status){
    ui->radioButtonX->setChecked(status);
}

void MainWindow::radioButtonY(bool status){
    ui->radioButtonY->setChecked(status);
}

void MainWindow::radioButtonL1(bool status){
    ui->radioButtonL2->setChecked(status);
}

void MainWindow::radioButtonR1(bool status){
    ui->radioButtonR2->setChecked(status);
}

void MainWindow::radioButtonSelect(bool status){
    ui->radioButtonSelect->setChecked(status);
}

void MainWindow::radioButtonStart(bool status){
    ui->radioButtonStart->setChecked(status);
}

void MainWindow::radioButtonLeft(bool status){
    ui->radioButtonLeft->setChecked(status);
}

void MainWindow::radioButtonRight(bool status){
    ui->radioButtonRight->setChecked(status);
}

void MainWindow::radioButtonUp(bool status){
    ui->radioButtonUp->setChecked(status);
}

void MainWindow::radioButtonDown(bool status){
    ui->radioButtonDown->setChecked(status);
}

void MainWindow::padBouttonLeftX (double value){
    int valueByte= (value * 128);
    ui->horizontalSliderLeftPad->setValue(valueByte);
}

void MainWindow::padBouttonLeftY (double value){
    int valueByte= (value * 128);
    ui->verticalSliderLeftPad->setValue(valueByte);
}

void MainWindow::padBouttonRightX (double value){
    int valueByte= (value * 128);
    ui->horizontalSliderRightPad->setValue(valueByte);
}

void MainWindow::padBouttonRightY (double value){
    int valueByte= (value * 128);
    ui->verticalSliderRightPad->setValue(valueByte);
}
