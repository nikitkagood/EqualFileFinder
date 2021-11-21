#pragma once

#include <QMainWindow>
#include <QtGui>
#include <QTableView>
#include <QMenu>
#include <QVector>
#include <QFileSystemModel>
#include <QFile>
#include <QTextStream>

#include "EqualFileFinder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void selectFolder1()
    {
        folder1 = current_path;
    }

    void selectFolder2()
    {
        folder2 = current_path;
    }

    void clearFolderSelection()
    {
        folder1.clear();
        folder2.clear();
    }

    void printResults();

    void saveResultsToFile();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_Start_clicked();

    void on_treeView_customContextMenuRequested(const QPoint &pos); //right mouse button

    void on_checkBox_OnlyTheSameFileNames_toggled(bool checked);

    void on_checkBox_CheckUnderlyingFolders_toggled(bool checked);

    void on_checkBox_ExcludeEmptyFiles_toggled(bool checked);

private:
    void setupCustomUi();

    Ui::MainWindow* ui;

    QFileSystemModel* directoryModel = new QFileSystemModel(this);
    QFileSystemModel* fileModel = new QFileSystemModel(this);

    QMenu* treeViewMenu;

    QAction* act_selectFolder1;
    QAction* act_selectFolder2;
    QAction* act_clearSelection;

    QString folder1;
    QString folder2;
    QString current_path;

    EqualFileFinder file_finder;
};

