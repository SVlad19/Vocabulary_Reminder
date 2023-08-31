#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "testform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tvDataBase->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    dataBase = std::make_unique<DataBase>();
    model = dataBase->GetModel();
    ui->tvDataBase->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    if(!((ui->leWord->text().isEmpty())||(ui->leTranscription->text().isEmpty()))){
        QSqlRecord temp = model->record();

        temp.setValue(0,ui->leWord->text());
        temp.setValue(1,ui->leTranscription->text());
        temp.setValue(2,0);

        model->insertRecord(model->rowCount(),temp);

        ui->leWord->clear();
        ui->leTranscription->clear();
        dataBase->fillData();
    }

}


void MainWindow::on_tvDataBase_clicked(const QModelIndex &index)
{
    this->index = index.row();
}


void MainWindow::on_btnRemove_clicked()
{
    model->removeRow(index);
    dataBase->fillData();
}


void MainWindow::on_btnTest_clicked()
{

    testForm = std::make_unique<TestForm>(dataBase->GetData());


    testForm->show();
}

