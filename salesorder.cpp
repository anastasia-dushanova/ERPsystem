#include "salesorder.h"
#include "ui_salesorder.h"

SalesOrder::SalesOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesOrder),
    currentEmployee("")
{
    ui->setupUi(this);

    db = new DataBaseConnector(this);
    balances = new InventoryBalances();
    arrears = new Arrears();
    qDebug() << arrears->size();
    setProduct();
}

SalesOrder::~SalesOrder()
{
    delete ui;
}

void SalesOrder::consider()
{
    qDebug() << "consider";
    QString contactName = ui->lineEdit_contactName->text();
    qDebug() << contactName;
    QString total = ui->lineEdit_total->text();
    qDebug() << total;
    QString date_reg = ui->dateEdit_reg->text();
    qDebug() << date_reg;
    QString date_ship = ui->dateEdit_shipment->text();
    qDebug() << date_ship;
    QString manager = ui->lineEdit_managerName->text();
    qDebug() << currentEmployee;

    int id = db->considerSalesOrder(currentEmployee, date_reg, date_ship, total);

    if(id != -1)
        QMessageBox::information(this, "Внимание", "Произошла запись в БД");

}

void SalesOrder::on_pushButton_save_clicked()
{
    //показываем счет на оплату задолженности и проданной ГП и пусконаладочным работам
    arrears->show();

}


void SalesOrder::on_pushButton_cancel_clicked()
{
    //очистить поля
    ui->lineEdit_SalesOrder_id->clear();
    ui->lineEdit_contactName->clear();
    ui->lineEdit_contractNumber->clear();
    ui->lineEdit_customer->clear();
    ui->lineEdit_discount->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_managerName->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_post->clear();
    ui->lineEdit_total->clear();
    ui->lineEdit_totalWithoutDiscount->clear();
    ui->lineEdit_vat->clear();
}

void SalesOrder::setProduct()
{
    QList<ProductInfo> listProduct = db->getProductInfo();
    QList<ProductInfo> listMaterial = db->getMaterialInfo();

    for(int i = 0; i < listProduct.size(); ++i)
        balances->addProduct(listProduct[i]);

    for(int i = 0; i < listMaterial.size(); ++i)
        balances->addMaterial(listMaterial[i]);
}

void SalesOrder::on_pushButton_clicked()
{
    balances->show();
}

