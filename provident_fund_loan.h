#ifndef PROVIDENT_FUND_LOAN_H
#define PROVIDENT_FUND_LOAN_H

#include <QMainWindow>
#include"result_1.h"
#include"result_2.h"


namespace Ui {
class Provident_Fund_loan;
}

class Provident_Fund_loan : public QMainWindow
{
    Q_OBJECT

public:
    explicit Provident_Fund_loan(QWidget *parent = nullptr);
    ~Provident_Fund_loan();

    float getsum();
    void setsum();
    void setyear();
    int getyear();
    float getrate();
    void setrate();
    result_1 *result1;
    result_2 *result2;


private slots:
    void on_pushButton_clicked();
    void receivesignal();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Provident_Fund_loan *ui;
    float sum;
    int year;
    float rate;

signals:
    void comloanshow();
    void mixloanshow();
//    void result1show();
//    void result2show();
};

#endif // PROVIDENT_FUND_LOAN_H
