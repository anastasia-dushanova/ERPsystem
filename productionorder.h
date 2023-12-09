#ifndef PRODUCTIONORDER_H
#define PRODUCTIONORDER_H

#include <QWidget>
#include <QMessageBox>
#include <technologicalcard.h>

namespace Ui {
class ProductionOrder;
}

class ProductionOrder : public QWidget
{
    Q_OBJECT

public:
    explicit ProductionOrder(QWidget *parent = nullptr);
    ~ProductionOrder();

private slots:
    void on_pushButton_specification_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::ProductionOrder *ui;

    TechnologicalCard* card;

};

#endif // PRODUCTIONORDER_H
