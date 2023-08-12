#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlRecord>

class DataBase;
class QSqlTableModel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_tvDataBase_clicked(const QModelIndex &index);

    void on_btnRemove_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<DataBase> dataBase;
    size_t index;
    QSqlTableModel* model;
    QMap<QString,QString> data;
};
#endif // MAINWINDOW_H
