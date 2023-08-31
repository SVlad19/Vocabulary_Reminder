#ifndef TESTFORM_H
#define TESTFORM_H

#include <QDialog>

namespace Ui {
class TestForm;
}

class TestForm : public QDialog
{
    Q_OBJECT

public:
    explicit TestForm(const QHash<QString,QString>& data,QWidget *parent = nullptr);
    ~TestForm();

private slots:
    void on_btnAnswer1_clicked();

    void on_btnAnswer2_clicked();

    void on_btnAnswer3_clicked();

private:
    Ui::TestForm *ui;
    QHash<QString,QString> data;
    int amountOfElements;
    QPair<QString,QString> correctAnswer;
    QVector<QString> randomKey;
    mutable int score;


    bool isAnswerCorrect(const QString& answer)const;
    void StartTest();
    void ChangeButtonColor(QPushButton* btn);
    void CheckScore();
};


#endif // TESTFORM_H
