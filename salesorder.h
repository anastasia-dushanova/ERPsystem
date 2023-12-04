#ifndef SALESORDER_H
#define SALESORDER_H

#include <QWidget>

namespace Ui {
class SalesOrder;
}

class SalesOrder : public QWidget
{
    Q_OBJECT

public:
    explicit SalesOrder(QWidget *parent = nullptr);
    ~SalesOrder();

private:
    Ui::SalesOrder *ui;
};

#endif // SALESORDER_H
