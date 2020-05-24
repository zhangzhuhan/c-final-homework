 #include "mainwindow.h"
#include"mixed_loan.h"
#include"provident_fund_loan.h"
#include"result_1.h"
#include"result_2.h"
#include <QApplication>
#include<QObject>
//主函数主要实现信号和槽的链接
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow comloan;//commercial loan
    mixed_loan mixloan;
    Provident_Fund_loan pfloan;
//    result_1 result1;
//    result_2 result2;
    comloan.show();
    QObject::connect(&comloan,SIGNAL(mixloanshow()),&mixloan,SLOT(receivesignal()));//商业贷款窗口发出信号，混合贷款窗口接受信号并处理
    QObject::connect(&comloan,SIGNAL(pfloanshow()),&pfloan,SLOT(receivesignal()));
//    QObject::connect(&comloan,SIGNAL(result1show()),&result1,SLOT(receivesignal()));
//    QObject::connect(&comloan,SIGNAL(result2show()),&result2,SLOT(receivesignal()));

    QObject::connect(&mixloan,SIGNAL(pfloanshow()),&pfloan,SLOT(receivesignal()));
    QObject::connect(&mixloan,SIGNAL(comloanshow()),&comloan,SLOT(receivesignal()));
//    QObject::connect(&mixloan,SIGNAL(result1show()),&result1,SLOT(receivesignal()));
//    QObject::connect(&mixloan,SIGNAL(result2show()),&result2,SLOT(receivesignal()));

    QObject::connect(&pfloan,SIGNAL(comloanshow()),&comloan,SLOT(receivesignal()));
    QObject::connect(&pfloan,SIGNAL(mixloanshow()),&mixloan,SLOT(receivesignal()));
//    QObject::connect(&pfloan,SIGNAL(result1show()),&result1,SLOT(receivesignal()));
//    QObject::connect(&pfloan,SIGNAL(result2show()),&result2,SLOT(receivesignal()));
    return a.exec();
}
