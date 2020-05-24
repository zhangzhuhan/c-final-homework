#include "result_2.h"
#include "ui_result_2.h"
//构造函数
result_2::result_2(int firstmonth_pament,int monthly_decrease,int interest,int total,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result_2)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(firstmonth_pament));
    ui->lineEdit_2->setText(QString::number(interest));
    ui->lineEdit_3->setText(QString::number(total));
    ui->lineEdit_4->setText(QString::number(monthly_decrease));

}

result_2::~result_2()
{
    delete ui;
}
//void result_2::receivesignal()
//{
//    this->show();
//}
