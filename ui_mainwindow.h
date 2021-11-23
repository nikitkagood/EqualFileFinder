/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Start;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_OnlyTheSameFileNames;
    QCheckBox *checkBox_CheckUnderlyingFolders;
    QCheckBox *checkBox_ExcludeEmptyFiles;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Status;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1017, 643);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Start = new QPushButton(centralwidget);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        sizePolicy1.setHeightForWidth(pushButton_Start->sizePolicy().hasHeightForWidth());
        pushButton_Start->setSizePolicy(sizePolicy1);
        pushButton_Start->setMinimumSize(QSize(40, 20));
        pushButton_Start->setMaximumSize(QSize(300, 100));

        gridLayout->addWidget(pushButton_Start, 3, 0, 1, 1, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy2);
        treeView->setMinimumSize(QSize(400, 500));
        treeView->setMaximumSize(QSize(2000, 2000));

        horizontalLayout->addWidget(treeView);

        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        sizePolicy2.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy2);
        listView->setMinimumSize(QSize(400, 500));
        listView->setMaximumSize(QSize(2000, 2000));

        horizontalLayout->addWidget(listView);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_OnlyTheSameFileNames = new QCheckBox(centralwidget);
        checkBox_OnlyTheSameFileNames->setObjectName(QString::fromUtf8("checkBox_OnlyTheSameFileNames"));

        horizontalLayout_2->addWidget(checkBox_OnlyTheSameFileNames);

        checkBox_CheckUnderlyingFolders = new QCheckBox(centralwidget);
        checkBox_CheckUnderlyingFolders->setObjectName(QString::fromUtf8("checkBox_CheckUnderlyingFolders"));

        horizontalLayout_2->addWidget(checkBox_CheckUnderlyingFolders);

        checkBox_ExcludeEmptyFiles = new QCheckBox(centralwidget);
        checkBox_ExcludeEmptyFiles->setObjectName(QString::fromUtf8("checkBox_ExcludeEmptyFiles"));
        checkBox_ExcludeEmptyFiles->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_ExcludeEmptyFiles);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 2, 1);

        label_Status = new QLabel(centralwidget);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_Status->sizePolicy().hasHeightForWidth());
        label_Status->setSizePolicy(sizePolicy3);
        label_Status->setMinimumSize(QSize(40, 20));
        label_Status->setMaximumSize(QSize(300, 100));
        label_Status->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_Status, 4, 0, 1, 1, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Equal file finder", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        checkBox_OnlyTheSameFileNames->setText(QCoreApplication::translate("MainWindow", "Only the same file names", nullptr));
        checkBox_CheckUnderlyingFolders->setText(QCoreApplication::translate("MainWindow", "Check underlying folders ", nullptr));
        checkBox_ExcludeEmptyFiles->setText(QCoreApplication::translate("MainWindow", "Exclude empty files", nullptr));
        label_Status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
