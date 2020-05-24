#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"result_1.h"
#include"result_2.h"
//主窗口，显示商业贷款
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float getsum();
    void setsum();
    void setyear();
    int getyear();
    float getrate();
    void setrate();
    result_1 *result1;
    result_2 *result2;



private slots:
    void on_pushButton_clicked();
    void receivesignal();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    float sum;
    int year;
    float rate;

signals:
    void mixloanshow();
    void pfloanshow();
//    void result1show();
//    void result2show();
};
#endif // MAINWINDOW_H
