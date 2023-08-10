#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tvDataBase->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    dataBase = std::make_unique<DataBase>();
    ui->tvDataBase->setModel(dataBase->GetModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

