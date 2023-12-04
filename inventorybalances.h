#ifndef INVENTORYBALANCES_H
#define INVENTORYBALANCES_H

#include <QWidget>

namespace Ui {
class InventoryBalances;
}

class InventoryBalances : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryBalances(QWidget *parent = nullptr);
    ~InventoryBalances();

private:
    Ui::InventoryBalances *ui;
};

#endif // INVENTORYBALANCES_H
