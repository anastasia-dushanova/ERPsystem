#include "technologicalcard.h"
#include "ui_technologicalcard.h"

TechnologicalCard::TechnologicalCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TechnologicalCard)
{
    ui->setupUi(this);

//    setFixedSize(QSize(1900, 1080));
    ui->tableWidget->setColumnWidth(0, 180);
    ui->tableWidget->setColumnWidth(1, 190);
    ui->tableWidget->setColumnWidth(2, 180);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

TechnologicalCard::~TechnologicalCard()
{
    delete ui;
}

void TechnologicalCard::addProductInfo(QString name, int inReserve)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);

    QTableWidgetItem* tab_name = new QTableWidgetItem(name);
    QTableWidgetItem* stock_name = new QTableWidgetItem(QString::number(inReserve));

    ui->tableWidget->setItem(row, 0, tab_name);
    ui->tableWidget->setItem(row, 2, stock_name);
}

void TechnologicalCard::addNewResource(QString product, QString material, int count)
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);

//    qDebug() << ui->tableWidget->rowCount();
    if(material.isEmpty()){


        QTableWidgetItem* tab_name = new QTableWidgetItem(product);
        QTableWidgetItem* stock_name = new QTableWidgetItem(QString::number(count));

        ui->tableWidget->setItem(row, 0, tab_name);
        ui->tableWidget->setItem(row, 2, stock_name);
    }else{

        QTableWidgetItem* tab_name = new QTableWidgetItem(material);
        QTableWidgetItem* stock_name = new QTableWidgetItem(QString::number(count));

        ui->tableWidget->setItem(row, 1, tab_name);
        ui->tableWidget->setItem(row, 2, stock_name);
    }
}

void TechnologicalCard::deleteResource()
{

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
}

QList<QPair<QString, QString> > TechnologicalCard::getProducts()
{

    QList<QPair<QString, QString>> list;
    int rows = ui->tableWidget->rowCount();

    for(int i = 0; i<rows; ++i){
        QString product{""};
        QString count{""};
        if(ui->tableWidget->item(i, 0))
            product = ui->tableWidget->item(i, 0)->text();

        if(ui->tableWidget->item(i, 0))
            count = ui->tableWidget->item(i, 2)->text();

        if(!product.isEmpty() && !count.isEmpty())
            list.append(qMakePair(product, count));


    }

    return list;
}

QList<QPair<QString, QString> > TechnologicalCard::getMaterials()
{
    QList<QPair<QString, QString>> list;
    int rows = ui->tableWidget->rowCount();

    for(int i = 0; i<rows; ++i){
        QString material{""};
        QString count{""};

        if(ui->tableWidget->item(i, 1))
            material = ui->tableWidget->item(i, 1)->text();

        if(ui->tableWidget->item(i, 2))
            count = ui->tableWidget->item(i, 2)->text();

        if(!material.isEmpty() && !count.isEmpty())
            list.append(qMakePair(material, count));


    }

    return list;
}

