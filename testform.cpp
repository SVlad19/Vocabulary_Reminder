#include "testform.h"
#include "ui_testform.h"
#include <random>

TestForm::TestForm(QMap<QString, QString> data, QWidget *parent):
    QDialog(parent),
    ui(new Ui::TestForm),
    data(data)
{
    ui->setupUi(this);

    this->data = data;

    StartTest();
}

TestForm::~TestForm()
{
    delete ui;
}

bool TestForm::isAnswerCorrect(const QString &answer) const
{
    if(correctAnswer.value() == answer){
        return true;
    }else{
        return false;
    }
}

void TestForm::StartTest()
{

   QMap<QString,QString> temp;
   static size_t numberOfTest = 0;
   size_t countOfElements = 0;

   for(auto it = data.constBegin(); it != data.constEnd();++it){
       if(countOfElements <= 3){
           temp[it.key()]=it.value();
           countOfElements++;
       }
   }
    correctAnswer = std::next(data.begin(),numberOfTest);
    numberOfTest++;

   ui->lWord->setText(correctAnswer.key());

   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distribution(1, 3);
   int randNumber = distribution(gen);
   size_t tempCount = 1;

   switch(randNumber){
   case 1:
       ui->btnAnswer1->setText(correctAnswer.value());

       for(auto it = data.constBegin(); it != data.constEnd();++it){
           if(tempCount == 1 && it != correctAnswer){
               ui->btnAnswer2->setText(it.value());
               tempCount++;
           }else if(tempCount == 2 && it != correctAnswer){
               ui->btnAnswer3->setText(it.value());
           }
       }
       break;
   case 2:
       ui->btnAnswer2->setText(correctAnswer.value());

       for(auto it = data.constBegin(); it != data.constEnd();++it){
           if(tempCount == 1 && it != correctAnswer){
               ui->btnAnswer1->setText(it.value());
               tempCount++;
           }else if(tempCount == 2 && it != correctAnswer){
               ui->btnAnswer3->setText(it.value());
           }

       }
       break;
   case 3:
       ui->btnAnswer3->setText(correctAnswer.value());

       for(auto it = data.constBegin(); it != data.constEnd();++it){
           if(tempCount == 1 && it != correctAnswer){
               ui->btnAnswer2->setText(it.value());
               tempCount++;
           }else if(tempCount == 2 && it != correctAnswer){
               ui->btnAnswer1->setText(it.value());
           }

       }
       break;
   default:
       break;
   }

}

void TestForm::on_btnAnswer1_clicked()
{
    if(isAnswerCorrect(ui->btnAnswer1->text())){
        StartTest();
    }
}


void TestForm::on_btnAnswer2_clicked()
{
    if(isAnswerCorrect(ui->btnAnswer2->text())){
        StartTest();
    }
}


void TestForm::on_btnAnswer3_clicked()
{
    if(isAnswerCorrect(ui->btnAnswer3->text())){
        StartTest();
    }
}

