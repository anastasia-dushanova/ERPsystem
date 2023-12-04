#ifndef PRODUCTIONORDER_H
#define PRODUCTIONORDER_H

#include <QWidget>

namespace Ui {
class ProductionOrder;
}

class ProductionOrder : public QWidget
{
    Q_OBJECT

public:
    explicit ProductionOrder(QWidget *parent = nullptr);
    ~ProductionOrder();

private:
    Ui::ProductionOrder *ui;
};

#endif // PRODUCTIONORDER_H
