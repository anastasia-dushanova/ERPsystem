#include "productionorder.h"
#include "ui_productionorder.h"

ProductionOrder::ProductionOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductionOrder)
{
    ui->setupUi(this);
}

ProductionOrder::~ProductionOrder()
{
    delete ui;
}
