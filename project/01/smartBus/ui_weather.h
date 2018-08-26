/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QLabel *label_info;
    QLabel *label_temp;
    QLabel *label_date;
    QLabel *label_wind;
    QLabel *label_weather_pic;
    QLabel *label_week;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QStringLiteral("Weather"));
        Weather->resize(304, 420);
        label_info = new QLabel(Weather);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setGeometry(QRect(59, 339, 199, 41));
        label_info->setAlignment(Qt::AlignCenter);
        label_temp = new QLabel(Weather);
        label_temp->setObjectName(QStringLiteral("label_temp"));
        label_temp->setGeometry(QRect(59, 299, 199, 41));
        label_temp->setAlignment(Qt::AlignCenter);
        label_date = new QLabel(Weather);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setGeometry(QRect(60, 83, 199, 56));
        label_date->setAlignment(Qt::AlignCenter);
        label_wind = new QLabel(Weather);
        label_wind->setObjectName(QStringLiteral("label_wind"));
        label_wind->setGeometry(QRect(60, 379, 199, 41));
        label_wind->setAlignment(Qt::AlignCenter);
        label_weather_pic = new QLabel(Weather);
        label_weather_pic->setObjectName(QStringLiteral("label_weather_pic"));
        label_weather_pic->setGeometry(QRect(60, 145, 201, 141));
        label_weather_pic->setAlignment(Qt::AlignCenter);
        label_week = new QLabel(Weather);
        label_week->setObjectName(QStringLiteral("label_week"));
        label_week->setGeometry(QRect(60, 20, 199, 57));
        label_week->setAlignment(Qt::AlignCenter);

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QApplication::translate("Weather", "Form", 0));
        label_info->setText(QString());
        label_temp->setText(QString());
        label_date->setText(QApplication::translate("Weather", "info", 0));
        label_wind->setText(QString());
        label_weather_pic->setText(QString());
        label_week->setText(QApplication::translate("Weather", "date", 0));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
