#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

class DataBase : public QObject
{
     Q_OBJECT
public:
    DataBase();
    QSqlTableModel* GetModel()const;
    const QHash<QString,QString>& GetData();
    void fillData();

private:
    QSqlDatabase database;
    std::unique_ptr<QSqlQuery> query;
    std::unique_ptr<QSqlTableModel> model;
    QHash<QString,QString> data;


};

#endif // DATABASE_H
