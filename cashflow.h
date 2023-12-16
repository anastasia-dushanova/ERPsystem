#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class CashFlow;
}

class CashFlow : public QWidget
{
    Q_OBJECT

public:
    explicit CashFlow(QWidget *parent = nullptr);
    ~CashFlow();

private slots:
    void on_pushButton_consider_clicked();

private:
    Ui::CashFlow *ui;
};

#endif // CASHFLOW_H
