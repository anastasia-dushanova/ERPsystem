#include "productionorder.h"
#include "ui_productionorder.h"

ProductionOrder::ProductionOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductionOrder)
{
    ui->setupUi(this);

//    setFixedSize(QSize(1900, 1080));
}

ProductionOrder::~ProductionOrder()
{
    delete ui;
}
