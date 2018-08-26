/********************************************************************************
** Form generated from reading UI file 'bus.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUS_H
#define UI_BUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bus
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_start;
    QLabel *label;
    QLabel *label_end;
    QLabel *label_3;
    QLabel *label_time;
    QLabel *label_info;
    QPushButton *label_bus_name;

    void setupUi(QWidget *Bus)
    {
        if (Bus->objectName().isEmpty())
            Bus->setObjectName(QStringLiteral("Bus"));
        Bus->resize(600, 550);
        layoutWidget = new QWidget(Bus);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 420, 371, 121));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_start = new QLabel(layoutWidget);
        label_start->setObjectName(QStringLiteral("label_start"));
        label_start->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_start, 1, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_end = new QLabel(layoutWidget);
        label_end->setObjectName(QStringLiteral("label_end"));
        label_end->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_end, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_time = new QLabel(layoutWidget);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_time, 3, 1, 1, 1);

        label_info = new QLabel(layoutWidget);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_info, 4, 0, 1, 2);

        label_bus_name = new QPushButton(layoutWidget);
        label_bus_name->setObjectName(QStringLiteral("label_bus_name"));

        gridLayout->addWidget(label_bus_name, 0, 0, 1, 2);


        retranslateUi(Bus);

        QMetaObject::connectSlotsByName(Bus);
    } // setupUi

    void retranslateUi(QWidget *Bus)
    {
        Bus->setWindowTitle(QApplication::translate("Bus", "Form", 0));
        label_2->setText(QApplication::translate("Bus", "start:", 0));
        label_start->setText(QApplication::translate("Bus", "start station", 0));
        label->setText(QApplication::translate("Bus", "end:", 0));
        label_end->setText(QApplication::translate("Bus", "end station", 0));
        label_3->setText(QApplication::translate("Bus", "time:", 0));
        label_time->setText(QApplication::translate("Bus", "total time", 0));
        label_info->setText(QApplication::translate("Bus", "total station number", 0));
        label_bus_name->setText(QApplication::translate("Bus", "station name", 0));
    } // retranslateUi

};

namespace Ui {
    class Bus: public Ui_Bus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUS_H
