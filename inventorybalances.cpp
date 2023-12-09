#include "inventorybalances.h"
#include "ui_inventorybalances.h"

InventoryBalances::InventoryBalances(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryBalances)
{
    ui->setupUi(this);
    ui->tableWidget_material->setColumnWidth(0,150);
    ui->tableWidget_material->setColumnWidth(1,150);
    ui->tableWidget_material->setColumnWidth(2,150);
    ui->tableWidget_material->setColumnWidth(3,150);
    ui->tableWidget_material->setColumnWidth(4,150);
    ui->tableWidget_material->setColumnWidth(5,150);
    ui->tableWidget_material->setColumnWidth(6,150);

    ui->tableWidget_products->setColumnWidth(0, 150);
    ui->tableWidget_products->setColumnWidth(1, 150);
    ui->tableWidget_products->setColumnWidth(2, 150);
    ui->tableWidget_products->setColumnWidth(3, 150);
}

InventoryBalances::~InventoryBalances()
{
    delete ui;
}
