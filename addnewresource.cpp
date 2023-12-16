#include "addnewresource.h"
#include "ui_addnewresource.h"

AddNewResource::AddNewResource(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewResource)
{
    ui->setupUi(this);
    ui->lineEdit_amountMaterial->setValidator(new QIntValidator());
}

AddNewResource::~AddNewResource()
{
    delete ui;
}

void AddNewResource::on_pushButton_cancel_clicked()
{

    ui->lineEdit_amountMaterial->clear();
    ui->lineEdit_material->clear();
    ui->lineEdit_product->clear();
    close();
}


void AddNewResource::on_pushButton_add_clicked()
{
    QString product = ui->lineEdit_product->text();
    QString material = ui->lineEdit_material->text();
    QString count = ui->lineEdit_amountMaterial->text();

    if(count.toInt() < 0)
        return;

    if((!product.isEmpty() && !count.isEmpty()) || (!material.isEmpty() && !count.isEmpty())){
        emit addNewResource(product, material, count.toInt());
        ui->lineEdit_amountMaterial->clear();
        ui->lineEdit_material->clear();
        ui->lineEdit_product->clear();
    }
}

