#include "database.h"

DataBase::DataBase()
{
    try{
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("./Vocabulary_Reminder");

        if(database.open()){
            query = std::make_unique<QSqlQuery>(database);
            query->exec("CREATE TABLE VocabularyReminder(Word TEXT, Translation TEXT, isLearned BOOLEAN)");

            model = std::make_unique<QSqlTableModel>(this,database);
            model->setTable("VocabularyReminder");
            model->select();
        }else{
            throw std::runtime_error("The database wasn`t open!");
        }

    }catch(const std::exception& ex){
        qDebug()<<ex.what();
    }

}

QSqlTableModel *DataBase::GetModel() const
{
    return model.get();
}
