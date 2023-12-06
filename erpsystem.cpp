#include "erpsystem.h"
#include "ui_erpsystem.h"

ERPsystem::ERPsystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ERPsystem)
{
    ui->setupUi(this);
    dbConnector = new DataBaseConnector(this);
    ui->stackedWidget->setCurrentIndex(0);
//    ProductionOrder* produc = new ProductionOrder(this);
//    produc->show();
//    ui->stackedWidget->addWidget(produc);
//    ui->stackedWidget->setCurrentIndex(2);
}

ERPsystem::~ERPsystem()
{
    delete ui;
}


void ERPsystem::on_pushButton_ok_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    int roleId = dbConnector->getRole(login, password);
    qDebug() << QString::number(roleId);
    switch(roleId){
    case static_cast<int>(Role::Role_Employee) : {
        startPorductionOrder();
        break;
    }
    case static_cast<int>(Role::Role_Manager) : {
        startSalesOrder();
        break;
    }
    default: {
        QMessageBox::warning(this, "Внимание", "Такого пользователя нет");
    }
    }
}

void ERPsystem::startPorductionOrder(){
    ui->stackedWidget->setCurrentIndex(1);
}

void ERPsystem::startSalesOrder(){
    ui->stackedWidget->setCurrentIndex(2);
}
