#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <QWidget>

namespace Ui {
class CashFlow;
}

class CashFlow : public QWidget
{
    Q_OBJECT

public:
    explicit CashFlow(QWidget *parent = nullptr);
    ~CashFlow();

private:
    Ui::CashFlow *ui;
};

#endif // CASHFLOW_H
