#include "salesorder.h"
#include "ui_salesorder.h"

SalesOrder::SalesOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesOrder)
{
    ui->setupUi(this);

//    setFixedSize(QSize(1900, 1080));
}

SalesOrder::~SalesOrder()
{
    delete ui;
}
