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

private:
    Ui::TestForm *ui;
    QMap<QString,QString> data;
};

#endif // TESTFORM_H
