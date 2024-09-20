/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Simplified_Chinese;
    QAction *action_Traditional_Chinese;
    QAction *action_exit;
    QAction *action_English;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_Simplified_Chinese = new QAction(MainWindow);
        action_Simplified_Chinese->setObjectName(QString::fromUtf8("action_Simplified_Chinese"));
        action_Simplified_Chinese->setCheckable(true);
        action_Simplified_Chinese->setChecked(true);
        action_Simplified_Chinese->setEnabled(true);
        action_Traditional_Chinese = new QAction(MainWindow);
        action_Traditional_Chinese->setObjectName(QString::fromUtf8("action_Traditional_Chinese"));
        action_Traditional_Chinese->setCheckable(true);
        action_Traditional_Chinese->setChecked(false);
        action_Traditional_Chinese->setEnabled(true);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_English = new QAction(MainWindow);
        action_English->setObjectName(QString::fromUtf8("action_English"));
        action_English->setCheckable(true);
        action_English->setChecked(false);
        action_English->setEnabled(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_exit);
        menu->addSeparator();
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(action_Simplified_Chinese);
        menu_2->addAction(action_Traditional_Chinese);
        menu_2->addAction(action_English);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Simplified_Chinese->setText(QCoreApplication::translate("MainWindow", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));
        action_Traditional_Chinese->setText(QCoreApplication::translate("MainWindow", "\347\271\201\344\275\223\344\270\255\346\226\207", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_English->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
#if QT_CONFIG(tooltip)
        action_English->setToolTip(QCoreApplication::translate("MainWindow", "English", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\350\257\255\350\250\200\345\210\207\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
