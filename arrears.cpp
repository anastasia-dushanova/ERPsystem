#include "arrears.h"
#include "ui_arrears.h"

Arrears::Arrears(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Arrears)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setWordWrap(true);
    ui->tableWidget->setColumnWidth(0, 250);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setColumnWidth(3, 250);
//    setFixedSize(1500, 530);
}

Arrears::~Arrears()
{
    delete ui;
}

void Arrears::on_pushButton_save_clicked()
{
    close();
}

