#include "cashflow.h"
#include "ui_cashflow.h"

CashFlow::CashFlow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashFlow)
{
    ui->setupUi(this);
}

CashFlow::~CashFlow()
{
    delete ui;
}

void CashFlow::on_pushButton_consider_clicked()
{
    qDebug() << "cashFrow";
    QString date = ui->dateEdit->text();
    qDebug() << date;
    QString amountPaid = ui->lineEdit_amountPaid->text();
    qDebug() << amountPaid;
    QString amountReceived = ui->lineEdit_amountReceived->text();
    qDebug() << amountReceived;
    QString bankReceiver = ui->lineEdit_bankReceiver->text();
    qDebug() << bankReceiver;
    QString bankSender = ui->lineEdit_bankSender->text();
    qDebug() << bankSender;
    QString counterpartyReceiver = ui->lineEdit_counterpartyReceiver->text();
    qDebug() << counterpartyReceiver;
    QString counterpartySender = ui->lineEdit_counterpartySender->text();
    qDebug() << counterpartySender;
    QString number = ui->lineEdit_number->text();
    qDebug() << number;
}

