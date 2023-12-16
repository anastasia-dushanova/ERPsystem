#include "productionorder.h"
#include "ui_productionorder.h"

ProductionOrder::ProductionOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductionOrder),
    currentEmployee("")
{
    ui->setupUi(this);

    dbConnector = new DataBaseConnector(this);

    newResource = new AddNewResource();

    connect(ui->comboBox_productType, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(slotSetReservedProducts(const QString&)));
    connect(newResource, SIGNAL(addNewResource(QString, QString, int)), this, SLOT(slotAddNewResource(QString, QString, int)));
}

ProductionOrder::~ProductionOrder()
{
    delete ui;
}

void ProductionOrder::on_pushButton_save_clicked()
{
    //сохранить

    QString foreman = ui->lineEdit_foreman->text();

    qDebug() << foreman;

    QString id = ui->lineEdit_prodOrder_id->text();

    qDebug() << id;

    QString total = ui->lineEdit_total->text();

    qDebug() << total;

    QList<QPair<QString, QString>> listProducts = ui->card->getProducts();
    QList<QPair<QString, QString>> listMaterail = ui->card->getMaterials();

    qDebug() << "listProducts.size()"<<listProducts.size();
    qDebug() << "listMaterail.size()"<<listMaterail.size();

    qDebug() << "currentEmployee "<<currentEmployee;

    QString date_reg = ui->dateEdit_reg->text();

    qDebug() << date_reg;

    QString date_ent = ui->dateEdit_entrance->text();

    qDebug() << date_ent;

    QString type = ui->comboBox_productType->currentText();

    qDebug() << type;

    //ВНИМАНИЕ - костыль, в списке ГП только один ГП
    int product_order_id = dbConnector->considerProductionOrder(currentEmployee, date_reg, date_ent, foreman, listProducts[0].first);

    if(listMaterail.size() != 0){
        int totalMaterial = dbConnector->updateMaterials(listMaterail);
        qDebug() << "totalMaterial = "<<totalMaterial;
    }

    if(product_order_id > 0)
        QMessageBox::information(this, "Сохранение", "Сохранено");
}


void ProductionOrder::on_pushButton_cancel_clicked()
{
    //очистить все поля
    ui->lineEdit_foreman->clear();
    ui->lineEdit_prodOrder_id->clear();
    ui->lineEdit_total->clear();
}

void ProductionOrder::slotSetReservedProducts(const QString& text)
{
    if(text != "Пусконаладочные работы")
        return;

    int productInfo = dbConnector->getProductInReserve();
//    qDebug() << QString::number(productInfo);

    ui->card->addProductInfo("ГП1", productInfo);
}


void ProductionOrder::on_pushButton_add_clicked()
{
    newResource->show();

}


void ProductionOrder::on_pushButton_delete_clicked()
{
    ui->card->deleteResource();
}

void ProductionOrder::slotAddNewResource(QString product, QString material, int count)
{
    ui->card->addNewResource(product, material, count);
}

