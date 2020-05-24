#include "commercial_loan.h"
#include "ui_commercial_loan.h"

Commercial_loan::Commercial_loan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Commercial_loan)
{
    ui->setupUi(this);
}

Commercial_loan::~Commercial_loan()
{
    delete ui;
}
