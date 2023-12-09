#include "technologicalcard.h"
#include "ui_technologicalcard.h"

TechnologicalCard::TechnologicalCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TechnologicalCard)
{
    ui->setupUi(this);

//    setFixedSize(QSize(1900, 1080));
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setColumnWidth(2, 150);
}

TechnologicalCard::~TechnologicalCard()
{
    delete ui;
}

void TechnologicalCard::on_pushButton_clicked()
{
    close();
}

