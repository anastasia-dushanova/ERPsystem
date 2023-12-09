#ifndef SALESORDER_H
#define SALESORDER_H

#include <QWidget>
#include <inventorybalances.h>

namespace Ui {
class SalesOrder;
}

class SalesOrder : public QWidget
{
    Q_OBJECT

public:
    explicit SalesOrder(QWidget *parent = nullptr);
    ~SalesOrder();

    void setLineEdit(QString line);

signals:
    void emitSalesOrder(QString line);

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_clicked();

private:
    Ui::SalesOrder *ui;

    InventoryBalances* balances;
};

#endif // SALESORDER_H
