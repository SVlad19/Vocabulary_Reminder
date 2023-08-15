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
    explicit TestForm(QMap<QString,QString> data,QWidget *parent = nullptr);
    ~TestForm();

private slots:
    void on_btnAnswer1_clicked();

    void on_btnAnswer2_clicked();

    void on_btnAnswer3_clicked();

private:
    Ui::TestForm *ui;
    QMap<QString,QString> data;
    QMap<QString,QString>::ConstIterator correctAnswer;

    bool isAnswerCorrect(const QString& answer)const;
    void StartTest();
};

#endif // TESTFORM_H
