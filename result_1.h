#ifndef RESULT_1_H
#define RESULT_1_H
#include <QWidget>
//等额本息的计算结果
namespace Ui {
class result_1;
}

class result_1 : public QWidget
{
    Q_OBJECT

public:
     explicit result_1(int monthly_payment,int interest,int total,QWidget *parent = nullptr);

    ~result_1();
//private slots:
//    void receivesignal();

private:
    Ui::result_1 *ui;
};

#endif // RESULT_1_H
