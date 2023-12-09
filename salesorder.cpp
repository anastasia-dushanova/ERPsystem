#include "salesorder.h"
#include "ui_salesorder.h"

SalesOrder::SalesOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesOrder)
{
    ui->setupUi(this);
    balances = new InventoryBalances();

//    setFixedSize(QSize(1900, 1080));
}

SalesOrder::~SalesOrder()
{
    delete ui;
}

void SalesOrder::setLineEdit(QString line)
{
    ui->lineEdit_SalesOrder_id->setText(line);
}

void SalesOrder::on_pushButton_save_clicked()
{
    //сохранить

}


void SalesOrder::on_pushButton_cancel_clicked()
{
    //очистить поля
}


void SalesOrder::on_pushButton_clicked()
{
    balances->show();
}

