#include "salesorder.h"
#include "ui_salesorder.h"

SalesOrder::SalesOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesOrder)
{
    ui->setupUi(this);
}

SalesOrder::~SalesOrder()
{
    delete ui;
}
