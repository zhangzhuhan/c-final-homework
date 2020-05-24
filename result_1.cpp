#include "result_1.h"
#include "ui_result_1.h"
//构造函数
result_1::result_1(int monthly_payment,int interest,int total,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::result_1)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(monthly_payment));
    ui->lineEdit_2->setText(QString::number(interest));
    ui->lineEdit_3->setText(QString::number(total));
}

result_1::~result_1()
{
    delete ui;
}

//void result_1::receivesignal()
//{
//    this->show();
//}
