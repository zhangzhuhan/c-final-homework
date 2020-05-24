#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<math.h>
//专门用来计算的类
class calculator
{
public:
//    static calculator* Get_Instance(){
//        static calculator calcu;
//        return &calcu;
//    }
    calculator();
     void cal_equal_principal_and_interest(float sum ,int year,float rate,int&monthly_payment,int &interest,int&total);
     //计算等额本息
     void cal_equal_principal(float sum,int year,float rate,int&firstmonth_pament,int &monthly_decrease,int &interest,int&total);
     //计算等额本金
};

#endif // CALCULATOR_H
