#include "mixed_loan.h"
#include "ui_mixed_loan.h"
#include"calculator.h"

mixed_loan::mixed_loan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mixed_loan)
{
    ui->setupUi(this);

}

mixed_loan::~mixed_loan()
{
    delete ui;
}

void mixed_loan::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())//等额本息
    {
        setclsum();
        setclrate();
        setpflsum();
        setpflrate();
        setyear();
        float clsum=getclsum();//cl=commercial loan
        float clrate=getclrate();
        float pflsum=getpflsum();//pfl=provident fund loan
        float pflrate=getpflrate();
        int year=getyear();
        int clmonthly_payment,clinterest,cltotal,pflmonthly_payment,pflinterest,pfltotal;
        calculator cal_cl,cal_pfl;
        cal_cl.cal_equal_principal_and_interest(clsum,year,clrate,clmonthly_payment,clinterest,cltotal);
        cal_pfl.cal_equal_principal_and_interest(pflsum,year,pflrate,pflmonthly_payment,pflinterest,pfltotal);//分别计算商业贷款和公积金贷款
        int monthly_payment=clmonthly_payment+pflmonthly_payment;
        int interest=clinterest+pflinterest;
        int total=cltotal+pfltotal;
        result1=new result_1(monthly_payment,interest,total);
        result1->show();
//        emit result1show();
    }
    else//等额本金，多一个每月递减
    {
        setclsum();
        setclrate();
        setpflsum();
        setpflrate();
        setyear();
        float clsum=getclsum();
        float clrate=getclrate();
        float pflsum=getpflsum();
        float pflrate=getpflrate();
        int year=getyear();
        int clfirstmonth_payment,clmonthly_decrease,clinterest,cltotal,pflfirstmonth_payment,pflmonthly_decrease,pflinterest,pfltotal;
        calculator cal_cl,cal_pfl;
        cal_cl.cal_equal_principal(clsum,year,clrate,clfirstmonth_payment,clmonthly_decrease,clinterest,cltotal);
        cal_pfl.cal_equal_principal(pflsum,year,pflrate,pflfirstmonth_payment,pflmonthly_decrease,pflinterest,pfltotal);
        int firstmonth_payment=clfirstmonth_payment+pflfirstmonth_payment;
        int interest=clinterest+pflinterest;
        int total=cltotal+pfltotal;
        int monthly_decrease=clmonthly_decrease+pflmonthly_decrease;
        result2=new result_2(firstmonth_payment,monthly_decrease,interest,total);
        result2->show();
//        emit result2show();
    }
}


void mixed_loan::on_comboBox_currentIndexChanged(int index)
{
    if(index==1)
    {
        this->hide();
        emit pfloanshow();
    }
    if(index==2)
    {
        this->hide();
        emit comloanshow();
    }
}
void mixed_loan::receivesignal()
{
    ui->comboBox->setCurrentIndex(0);
    this->show();
}
void mixed_loan::setclsum()
{
    clsum=ui->doubleSpinBox->value();
}
float mixed_loan::getclsum()
{
    return clsum;
}
void mixed_loan::setpflsum()
{
    pflsum=ui->doubleSpinBox_3->value();
}
float mixed_loan::getpflsum()
{
    return pflsum;
}
void mixed_loan::setyear()
{
    switch (ui->comboBox_4->currentIndex())
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
int mixed_loan::getyear()
{
    return year;
}
void mixed_loan::setclrate()
{
    clrate=ui->doubleSpinBox_2->value()/100;
}
float mixed_loan::getclrate()
{
    return clrate;
}
void mixed_loan::setpflrate()
{
    pflrate=ui->doubleSpinBox_4->value()/100;
}
float mixed_loan::getpflrate()
{
    return pflrate;
}

