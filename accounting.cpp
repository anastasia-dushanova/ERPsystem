#include "accounting.h"
#include "ui_accounting.h"

Accounting::Accounting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accounting)
{
    ui->setupUi(this);
}

Accounting::~Accounting()
{
    delete ui;
}

void Accounting::on_pushButton_show_clicked()
{
    emit showSalesOrder();
}


void Accounting::on_pushButton_consider_clicked()
{
    //... Учесть
    //внести или изменить данные в БД
    emit consider();
}
