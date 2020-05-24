#ifndef RESULT_2_H
#define RESULT_2_H

#include <QWidget>
//显示等额本金的计算结果
namespace Ui {
class result_2;
}

class result_2 : public QWidget
{
    Q_OBJECT

public:
    explicit result_2(int firstmonth_pament,int monthly_decrease,int interest,int total,QWidget *parent = nullptr);
    ~result_2();
//private slots:
//    void receivesignal();

private:
    Ui::result_2 *ui;
};

#endif // RESULT_2_H
