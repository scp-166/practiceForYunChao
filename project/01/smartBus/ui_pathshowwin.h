/********************************************************************************
** Form generated from reading UI file 'pathshowwin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHSHOWWIN_H
#define UI_PATHSHOWWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PathShowWin
{
public:

    void setupUi(QWidget *PathShowWin)
    {
        if (PathShowWin->objectName().isEmpty())
            PathShowWin->setObjectName(QStringLiteral("PathShowWin"));
        PathShowWin->resize(900, 600);

        retranslateUi(PathShowWin);

        QMetaObject::connectSlotsByName(PathShowWin);
    } // setupUi

    void retranslateUi(QWidget *PathShowWin)
    {
        PathShowWin->setWindowTitle(QApplication::translate("PathShowWin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class PathShowWin: public Ui_PathShowWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHSHOWWIN_H
