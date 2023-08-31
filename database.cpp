#include "database.h"
#include <random>

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

            fillData();
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

const QHash<QString, QString>& DataBase::GetData()
{

    return data;

}

void DataBase::fillData()
{
    if(query->exec("SELECT Word, Translation FROM VocabularyReminder")){
        qDebug()<<"Select ok!";
        while(query->next()){
                    QString word = query->value("Word").toString();
                    QString transcript = query->value("Translation").toString();
                    data[word] = transcript;
            }
    }else{
        qDebug()<<"Select didn`t work!";
    }

    for(QHash<QString,QString>::ConstIterator it = data.constBegin(); it != data.constEnd();++it){
        qDebug()<<"Key = "<<it.key() << " Value = "<<it.value()<<"\n";
    }
}
