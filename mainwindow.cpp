#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupCustomUi();
}

void MainWindow::setupCustomUi()
{
    //custom ui
    QString sPath = "C:/";

    directoryModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs); //displays only directories
    directoryModel->setRootPath(sPath);
    ui->treeView->setModel(directoryModel);
    ui->treeView->setColumnWidth(0, 200);
    ui->treeView->setColumnHidden(1, true);
    ui->treeView->setColumnHidden(2, true);
    ui->treeView->setColumnHidden(3, true);

    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files); //displays only files
    fileModel->setRootPath(sPath);
    ui->listView->setModel(fileModel);

    //right click menu
    treeViewMenu = new QMenu(ui->treeView);

    act_selectFolder1 = new QAction{"Select folder 1", this};
    act_selectFolder2 = new QAction{"Select folder 2", this};
    act_clearSelection = new QAction{"Clear selection", this};

    treeViewMenu->addAction(act_selectFolder1);
    connect(act_selectFolder1, &QAction::triggered, this, &MainWindow::selectFolder1);
    treeViewMenu->addAction(act_selectFolder2);
    connect(act_selectFolder2, &QAction::triggered, this, &MainWindow::selectFolder2);
    treeViewMenu->addAction(act_clearSelection);
    connect(act_clearSelection, &QAction::triggered, this, &MainWindow::clearFolderSelection);

    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
}


void MainWindow::printResults()
{
    //conversion from 2d vector<string> to 2d QVector<QString>
//        QVector<QVector<QString>> conversion_result;

//        const auto& std2dvec = file_finder.getSearchResults();

//        std::transform(std2dvec.begin(), std2dvec.end(), std::back_inserter(conversion_result), [](const std::vector<std::string>& value)
//        {
//            QVector<QString> result;
//            result.reserve(value.size());

//            for (const auto& str : value)
//            {
//                result.push_back(QString::fromStdString(str));
//            }

//            return result;
//        }
//        );

    for(const auto& vec : file_finder.getSearchResults())
    {
        for(const auto& i : vec)
        {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
    }
}

void MainWindow::saveResultsToFile()
{
    std::ofstream stream("search_results.txt");

    stream << "Results of the search are:" << '\n' << '\n';

    if (stream.is_open())
    {
        for(const auto& vec : file_finder.getSearchResults())
        {
            for(const auto& i : vec)
            {
                stream << i << '\n';
            }
            stream << '\n';
        }
    }
    else
    {
        std::cout << "Unable to open the file" << std::endl;
    }

}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    ui->listView->setRootIndex(fileModel->setRootPath(
       directoryModel->fileInfo(index).absoluteFilePath()
    ));

}

void MainWindow::on_treeView_customContextMenuRequested(const QPoint &pos)
{
    current_path = directoryModel->fileInfo(ui->treeView->indexAt(pos)).absoluteFilePath();

    treeViewMenu->popup(ui->treeView->viewport()->mapToGlobal(pos));
}

void MainWindow::on_pushButton_Start_clicked()
{
    LOG_DURATION(__FUNCTION__)

    ui->label_Status->setText("Searching...");

    try
    {
        file_finder.findEqualFiles(folder1.toStdString(), folder2.toStdString());
    }
    catch (std::string str)
    {
        std::cerr << str << std::endl;
        ui->label_Status->setText(QString::fromStdString(str));
        return;
    }
    catch (std::runtime_error re)
    {
        std::cerr << re.what() << std::endl;
        return;
    }
    catch (...)
    {
        exit(-99);
    }

    printResults();

    if(file_finder.getSearchResults().size() > 0)
    {
        saveResultsToFile();
        ui->label_Status->setText("Done. Saved into \"search results.txt\".");
    }
    else
    {
        ui->label_Status->setText("Done. No equal files found.");
    }

}

void MainWindow::on_checkBox_OnlyTheSameFileNames_toggled(bool checked)
{
    file_finder.changeSetting(EqualFileFinder::Settings::TheSameFileNames, checked);
}

void MainWindow::on_checkBox_CheckUnderlyingFolders_toggled(bool checked)
{
    file_finder.changeSetting(EqualFileFinder::Settings::FolderRecursion, checked);
}

void MainWindow::on_checkBox_ExcludeEmptyFiles_toggled(bool checked)
{
    file_finder.changeSetting(EqualFileFinder::Settings::ExcludeEmptyFiles, checked);
}
