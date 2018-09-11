/********************************************************************************
** Form generated from reading UI file 'smartbus.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTBUS_H
#define UI_SMARTBUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smartBus
{
public:

    void setupUi(QWidget *smartBus)
    {
        if (smartBus->objectName().isEmpty())
            smartBus->setObjectName(QStringLiteral("smartBus"));
        smartBus->resize(1280, 640);

        retranslateUi(smartBus);

        QMetaObject::connectSlotsByName(smartBus);
    } // setupUi

    void retranslateUi(QWidget *smartBus)
    {
        smartBus->setWindowTitle(QApplication::translate("smartBus", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class smartBus: public Ui_smartBus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTBUS_H
