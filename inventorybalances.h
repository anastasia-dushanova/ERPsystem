#ifndef INVENTORYBALANCES_H
#define INVENTORYBALANCES_H

#include <QWidget>
#include <productinfo.h>

namespace Ui {
class InventoryBalances;
}

class InventoryBalances : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryBalances(QWidget *parent = nullptr);
    ~InventoryBalances();

    void addProduct(ProductInfo pr);
    void addMaterial(ProductInfo pr);

private slots:
    void on_pushButton_clicked();

private:
    Ui::InventoryBalances *ui;
};

#endif // INVENTORYBALANCES_H
