#include "cashflow.h"
#include "ui_cashflow.h"

CashFlow::CashFlow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashFlow)
{
    ui->setupUi(this);
}

CashFlow::~CashFlow()
{
    delete ui;
}
