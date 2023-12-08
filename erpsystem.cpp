#include "erpsystem.h"
#include "ui_erpsystem.h"

ERPsystem::ERPsystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ERPsystem)
{
    ui->setupUi(this);
    dbConnector = new DataBaseConnector(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_exit->hide();
    ui->label_type->hide();
//    ProductionOrder* produc = new ProductionOrder(this);
//    produc->show();
//    ui->stackedWidget->addWidget(produc);
//    ui->stackedWidget->setCurrentIndex(2);

//    ui->stackedWidget->setFixedSize(QSize(1890, 930));
}

ERPsystem::~ERPsystem()
{
    delete ui;
}


void ERPsystem::on_pushButton_ok_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if(login.isEmpty() || password.isEmpty()){
        QMessageBox::warning(this, "Внимание", "Заполните поля логина и пароля");
        return;
    }

    int roleId = dbConnector->getRole(login, password);
//    qDebug() << QString::number(roleId);
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
        break;
    }
    }
}

void ERPsystem::startPorductionOrder(){
    ui->label_type->show();
    ui->label_type->clear();
    ui->label_type->setText("Производственный отдел");
    ui->pushButton_exit->show();
    ui->lineEdit_login->clear();
    ui->lineEdit_password->clear();
    ui->stackedWidget->setCurrentIndex(2);
}

void ERPsystem::startSalesOrder(){
    ui->label_type->show();
    ui->label_type->clear();
    ui->label_type->setText("Отдел продаж");
    ui->pushButton_exit->show();
    ui->lineEdit_login->clear();
    ui->lineEdit_password->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void ERPsystem::on_pushButton_exit_clicked()
{
    ui->label_type->hide();
    ui->pushButton_exit->hide();
    ui->stackedWidget->setCurrentIndex(0);
}

