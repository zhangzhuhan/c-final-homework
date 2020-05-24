#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"calculator.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())//选中等额本息
    {
        setsum();
        setyear();
        setrate();
        int monthly_payment,interest,total;//月供、利息、本息总额
        int y=getyear();
        float sum=getsum();
        float rate=getrate();
        calculator cal;
        qDebug()<<sum<<year<<rate;
        cal.cal_equal_principal_and_interest(sum,y,rate,monthly_payment,interest,total);
        qDebug()<<interest;
        result1=new result_1(monthly_payment,interest,total);
        result1->show();
//        emit result1show();
    }
    else//选中等额本金
    {
        setsum();
        setyear();
        setrate();
        float sum=getsum();
        int y=getyear();
        float rate=getrate();
        int firstmonth_pament, monthly_decrease, interest,total;//首月月供、每月递减、利息、本息总额
        calculator cal;
        cal.cal_equal_principal(sum,y,rate,firstmonth_pament,monthly_decrease,interest,total);
        result2=new result_2(firstmonth_pament,monthly_decrease,interest,total);
        result2->show();
//        emit result2show();
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==2)
    {
        this->hide();
        emit mixloanshow();
    }
    else if(index==1)
    {
        this->hide();
       emit pfloanshow();
    }

}
void MainWindow::receivesignal()
{
    ui->comboBox->setCurrentIndex(0);
    this->show();
}

void MainWindow::setsum()//贷款总额
{
    sum=ui->doubleSpinBox_2->value();

}
float MainWindow::getsum()
{
    return sum;
}
void MainWindow::setyear()
{
    switch (ui->comboBox_4->currentIndex())//按揭年数
    {
    case 0:year=25;break;
    case 1:year=24;break;
    case 2:year=23;break;
    case 3:year=22;break;
    case 4:year=21;break;
    case 5:year=20;break;
    case 6:year=19;break;
    case 7:year=18;break;
    case 8:year=17;break;
    case 9:year=16;break;
    case 10:year=15;break;
    case 11:year=14;break;
    case 12:year=13;break;
    case 13:year=12;break;
    case 14:year=11;break;
    case 15:year=10;break;
    case 16:year=9;break;
    case 17:year=8;break;
    case 18:year=7;break;
    case 19:year=6;break;
    case 20:year=5;break;
    case 21:year=4;break;
    case 22:year=3;break;
    case 23:year=2;break;
    case 24:year=1;break;
    default:year=0;break;
    }
}
int MainWindow::getyear()
{
    return year;
}
void MainWindow::setrate()//利率
{
    rate=ui->doubleSpinBox->value()/100;
}
float MainWindow::getrate()
{
    return rate;
}




















