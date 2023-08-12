#include "testform.h"
#include "ui_testform.h"

TestForm::TestForm(QMap<QString, QString> data, QWidget *parent):
    QDialog(parent),
    ui(new Ui::TestForm),
    data(data)
{
    ui->setupUi(this);

    for(QMap<QString,QString>::ConstIterator it = data.constBegin(); it != data.constEnd();++it){
        qDebug()<<"Key = "<<it.key() << " Value = "<<it.value()<<"\n";
    }


}

TestForm::~TestForm()
{
    delete ui;
}
