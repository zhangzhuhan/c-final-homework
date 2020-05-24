#include "calculator.h"


calculator::calculator()
{

}
void calculator::cal_equal_principal_and_interest(float sum ,int year,float rate,int&monthly_payment,int&interest,int&total)
{
    sum=sum*10000;
    float monthrate=rate/12;
    int month=year*12;
    monthly_payment=round((sum*monthrate*pow((1+monthrate),month))/(pow((1+monthrate),month)-1));
    interest=round((month*sum*monthrate*pow((1+monthrate),month))/(pow((1+monthrate),month)-1)-sum);
    total=round((month*sum*monthrate*pow((1+monthrate),month))/(pow((1+monthrate),month)-1));

}
void calculator::cal_equal_principal(float sum, int year, float rate, int &firstmonth_pament, int &monthly_decrease, int&interest,int &total)
{
    sum=sum*10000;
    float monthrate=rate/12;
    int month=year*12;
    monthly_decrease=round((sum/month)*monthrate);
    firstmonth_pament=round(sum/month+sum*monthrate);
    interest=round((month+1)*sum*monthrate/2);
    total=round((month+1)*sum*monthrate/2+sum);
}
