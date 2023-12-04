#include "inventorybalances.h"
#include "ui_inventorybalances.h"

InventoryBalances::InventoryBalances(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryBalances)
{
    ui->setupUi(this);
}

InventoryBalances::~InventoryBalances()
{
    delete ui;
}
