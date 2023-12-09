#include "productionorder.h"
#include "ui_productionorder.h"

ProductionOrder::ProductionOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductionOrder)
{
    ui->setupUi(this);

//    setFixedSize(QSize(1900, 1080));
    ui->tableWidget_materials->setColumnWidth(0, 150);
    ui->tableWidget_materials->setColumnWidth(1, 150);
    ui->tableWidget_materials->setColumnWidth(2, 150);
    ui->tableWidget_materials->setColumnWidth(3, 150);

    ui->tableWidget_steps->setColumnWidth(0, 170);
    ui->tableWidget_steps->setColumnWidth(0, 150);

    card = new TechnologicalCard();
}

ProductionOrder::~ProductionOrder()
{
    delete ui;
}

void ProductionOrder::on_pushButton_specification_clicked()
{

    card->show();
}


void ProductionOrder::on_pushButton_save_clicked()
{
    //сохранить
    QMessageBox::information(this, "Сохранение", "Сохранено");
}


void ProductionOrder::on_pushButton_cancel_clicked()
{
    //очистить все поля
}

