#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <QWidget>
#include <QDebug>
#include <salesorder.h>

namespace Ui {
class Accounting;
}

class Accounting : public QWidget
{
    Q_OBJECT

public:
    explicit Accounting(QWidget *parent = nullptr);
    ~Accounting();

signals:
    void consider();
    void showSalesOrder();

private slots:
    void on_pushButton_show_clicked();

    void on_pushButton_consider_clicked();

private:
    Ui::Accounting *ui;
};

#endif // ACCOUNTING_H
