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

    ui->tableWidget_products->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_material->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

InventoryBalances::~InventoryBalances()
{
    delete ui;
}

void InventoryBalances::addProduct(ProductInfo pr)
{
    int row = ui->tableWidget_products->rowCount();
    ui->tableWidget_products->setRowCount(row+1);

    QTableWidgetItem* productId = new QTableWidgetItem(QString::number(pr.getProductId()));
    QTableWidgetItem* name = new QTableWidgetItem(pr.getName());
    QTableWidgetItem* unitMeasure = new QTableWidgetItem(pr.getUnitMeasure());
    QTableWidgetItem* costPrice = new QTableWidgetItem(QString::number(pr.getCostPrice()));
    QTableWidgetItem* inStock = new QTableWidgetItem(QString::number(pr.getInStock()));
    QTableWidgetItem* inReserve = new QTableWidgetItem(QString::number(pr.getInReserve()));
    QTableWidgetItem* available = new QTableWidgetItem(QString::number(pr.getAvailable()));

    ui->tableWidget_products->setItem(row, 0, productId);
    ui->tableWidget_products->setItem(row, 1, name);
    ui->tableWidget_products->setItem(row, 2, unitMeasure);
    ui->tableWidget_products->setItem(row, 3, costPrice);
    ui->tableWidget_products->setItem(row, 4, inStock);
    ui->tableWidget_products->setItem(row, 5, inReserve);
    ui->tableWidget_products->setItem(row, 6, available);
}

void InventoryBalances::addMaterial(ProductInfo pr)
{
    int row = ui->tableWidget_material->rowCount();
    ui->tableWidget_material->setRowCount(row+1);

    QTableWidgetItem* productId = new QTableWidgetItem(QString::number(pr.getProductId()));
    QTableWidgetItem* name = new QTableWidgetItem(pr.getName());
    QTableWidgetItem* unitMeasure = new QTableWidgetItem(pr.getUnitMeasure());
    QTableWidgetItem* costPrice = new QTableWidgetItem(QString::number(pr.getCostPrice()));

    ui->tableWidget_material->setItem(row, 0, productId);
    ui->tableWidget_material->setItem(row, 1, name);
    ui->tableWidget_material->setItem(row, 2, unitMeasure);
    ui->tableWidget_material->setItem(row, 3, costPrice);

}

void InventoryBalances::on_pushButton_clicked()
{
    close();
}

