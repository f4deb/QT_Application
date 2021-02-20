/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *applyButton;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *parityBox;
    QComboBox *serialPortInfoListBox;
    QComboBox *stopBitsBox;
    QComboBox *baudRateBox;
    QComboBox *dataBitsBox;
    QComboBox *flowControlBox;
    QLabel *label;
    QLabel *baudRateLabel;
    QLabel *dataBitsLabel;
    QLabel *parityLabel;
    QLabel *stopBitsLabel;
    QLabel *flowControlLabel;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(267, 232);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsDialog->sizePolicy().hasHeightForWidth());
        SettingsDialog->setSizePolicy(sizePolicy);
        SettingsDialog->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(SettingsDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);

        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QString::fromUtf8("selectBox"));
        selectBox->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        parityBox = new QComboBox(selectBox);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        gridLayout->addWidget(parityBox, 18, 1, 1, 1);

        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 5, 1, 1, 1);

        stopBitsBox = new QComboBox(selectBox);
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout->addWidget(stopBitsBox, 20, 1, 1, 1);

        baudRateBox = new QComboBox(selectBox);
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));
        baudRateBox->setLayoutDirection(Qt::LeftToRight);
        baudRateBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(baudRateBox, 11, 1, 1, 1);

        dataBitsBox = new QComboBox(selectBox);
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout->addWidget(dataBitsBox, 15, 1, 1, 1);

        flowControlBox = new QComboBox(selectBox);
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout->addWidget(flowControlBox, 22, 1, 1, 1);

        label = new QLabel(selectBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 0, 1, 1);

        baudRateLabel = new QLabel(selectBox);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));

        gridLayout->addWidget(baudRateLabel, 11, 0, 1, 1);

        dataBitsLabel = new QLabel(selectBox);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        gridLayout->addWidget(dataBitsLabel, 15, 0, 1, 1);

        parityLabel = new QLabel(selectBox);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        gridLayout->addWidget(parityLabel, 18, 0, 1, 1);

        stopBitsLabel = new QLabel(selectBox);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        gridLayout->addWidget(stopBitsLabel, 20, 0, 1, 1);

        flowControlLabel = new QLabel(selectBox);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        gridLayout->addWidget(flowControlLabel, 22, 0, 1, 1);


        gridLayout_3->addWidget(selectBox, 0, 0, 1, 1);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Settings", nullptr));
        applyButton->setText(QCoreApplication::translate("SettingsDialog", "Apply", nullptr));
        selectBox->setTitle(QCoreApplication::translate("SettingsDialog", "Select Serial Port Server", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "TextLabel", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("SettingsDialog", "BaudRate:", nullptr));
        dataBitsLabel->setText(QCoreApplication::translate("SettingsDialog", "Data bits:", nullptr));
        parityLabel->setText(QCoreApplication::translate("SettingsDialog", "Parity:", nullptr));
        stopBitsLabel->setText(QCoreApplication::translate("SettingsDialog", "Stop bits:", nullptr));
        flowControlLabel->setText(QCoreApplication::translate("SettingsDialog", "Flow control:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
