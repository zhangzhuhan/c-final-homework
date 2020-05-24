#ifndef MIXED_LOAN_H
#define MIXED_LOAN_H

#include <QMainWindow>
#include"result_1.h"
#include"result_2.h"

//组合贷款

namespace Ui {
class mixed_loan;
}

class mixed_loan : public QMainWindow
{
    Q_OBJECT

public:
    explicit mixed_loan(QWidget *parent = nullptr);
    ~mixed_loan();

    float getclsum();
    void setclsum();
    float getpflsum();
    void setpflsum();
    void setyear();
    int getyear();
    float getclrate();
    void setclrate();
    float getpflrate();
    void setpflrate();
    result_1 *result1;
    result_2 *result2;


private slots:
    void on_pushButton_clicked();
    void receivesignal();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::mixed_loan *ui;
    float clsum,pflsum,clrate,pflrate;
    int year;
signals:
    void comloanshow();
    void pfloanshow();
//    void result1show();
//    void result2show();

};

#endif // MIXED_LOAN_H
