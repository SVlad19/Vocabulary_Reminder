#include "testform.h"
#include "ui_testform.h"
#include <QTimer>
#include <random>
#include <QMessageBox>

TestForm::TestForm(const QHash<QString, QString>& data, QWidget *parent):
    QDialog(parent),
    ui(new Ui::TestForm),
    data(data),
    amountOfElements(data.size()<13?data.size():13),
    randomKey(amountOfElements),
    score(0)
{
    ui->setupUi(this);

    int counter = 0;

    for(auto it = data.cbegin(); it != data.cend(); ++it){
        if(counter < randomKey.capacity()){
             randomKey[counter++] = it.key();
        }else{
            break;
        }
    }

    StartTest();
}

TestForm::~TestForm()
{
    delete ui;
}

bool TestForm::isAnswerCorrect(const QString &answer) const
{
    if(correctAnswer.second == answer){
        score++;
        return true;
    }else{
        score--;
        return false;
    }
}

void TestForm::StartTest()
{
    if(randomKey.size() > 3){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distributionForCorrectAnswer(0, randomKey.size()-1);
    std::uniform_int_distribution<> distributionForButton(0, 2);

    int correctIndex = distributionForCorrectAnswer(gen);
    int correctButton = distributionForButton(gen);

    correctAnswer = qMakePair(randomKey[correctIndex],data[randomKey[correctIndex]]);

    QVector<QPushButton*> buttons = findChildren<QPushButton*>();

    buttons[correctButton]->setText(correctAnswer.second);
    ui->lWord->setText(correctAnswer.first);

    randomKey.removeOne(randomKey[correctIndex]);

    std::uniform_int_distribution<> distributionForIndex(0, randomKey.size()-1);

    int prevIndex = -1;

    QVector<int> indexAlreadyWas;
    for(const auto& button: buttons){
        int Index = distributionForIndex(gen);
        if(button != buttons[correctButton]){
            if(Index != prevIndex && correctAnswer.second != data[randomKey[Index]]){
                 button->setText(data[randomKey[Index]]);
            }else{
                 Index = distributionForIndex(gen);
                 button->setText(data[randomKey[Index]]);
            }
        }
    }
    }else{
        CheckScore();
        close();
    }

}

void TestForm::ChangeButtonColor(QPushButton *button)
{

     button->setStyleSheet("background-color: red; color: white; border: 2px solid #1D0F0F; border-radius: 8px; padding: 3;");

     QTimer *timer = new QTimer(this);
     connect(timer, &QTimer::timeout, this, [=]() {
           button->setStyleSheet("background-color: #7B586B; color: white; border: 2px solid #1D0F0F; border-radius: 8px; padding: 3;");
           timer->deleteLater();
       });

     timer->start(400);
}

void TestForm::CheckScore()
{
    QMessageBox msgBox;

    if(score == 10 || score == amountOfElements){
      QString strScore = QString("Congratulations! You have scored %1 points!").arg(score);
      QMessageBox::information(this, "Congratulations!", strScore);
    }else if(score >= 10/2 || score >= amountOfElements/2){
      QString strScore = QString("Not bad! You have scored %1 points!").arg(score);
      QMessageBox::information(this, "Not bad!", strScore);
    }else{
      QString strScore = QString("Badly! You have scored %1 points!").arg(score);
      QMessageBox::information(this, "Badly!", strScore);
    }
}

void TestForm::on_btnAnswer1_clicked()
{
    if(isAnswerCorrect(ui->btnAnswer1->text())){
        StartTest();
    }else{
        ChangeButtonColor(ui->btnAnswer1);
    }
}


void TestForm::on_btnAnswer2_clicked()
{
    if(isAnswerCorrect(ui->btnAnswer2->text())){
        StartTest();
    }else{
        ChangeButtonColor(ui->btnAnswer2);
    }
}


void TestForm::on_btnAnswer3_clicked()
{
    if(isAnswerCorrect(ui->btnAnswer3->text())){
        StartTest();
    }else{
        ChangeButtonColor(ui->btnAnswer3);
    }
}

