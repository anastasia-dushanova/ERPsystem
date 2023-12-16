#ifndef SALESORDER_H
#define SALESORDER_H

#include <QWidget>
#include <QMessageBox>
#include <databaseconnector.h>
#include <productinfo.h>
#include <inventorybalances.h>
#include <arrears.h>

namespace Ui {
class SalesOrder;
}

class SalesOrder : public QWidget
{
    Q_OBJECT

public:
    explicit SalesOrder(QWidget *parent = nullptr);
    ~SalesOrder();

    void consider();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_clicked();

public slots:
    void setCurrentEmployee(QString emp) { this->currentEmployee=emp; }

private:


    Ui::SalesOrder *ui;

    DataBaseConnector* db;

    InventoryBalances* balances;

    Arrears* arrears;

    void setProduct();

    QString currentEmployee;

};

#endif // SALESORDER_H
