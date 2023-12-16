#ifndef PRODUCTIONORDER_H
#define PRODUCTIONORDER_H

#include <QWidget>
#include <QMessageBox>
#include <databaseconnector.h>
#include <addnewresource.h>

namespace Ui {
class ProductionOrder;
}

class ProductionOrder : public QWidget
{
    Q_OBJECT

public:
    explicit ProductionOrder(QWidget *parent = nullptr);
    ~ProductionOrder();

public slots:
    void setCurrentEmployee(QString login) { this->currentEmployee = login; }

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

    void slotSetReservedProducts(const QString& text);

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void slotAddNewResource(QString product, QString material, int count);

private:

    Ui::ProductionOrder *ui;

    DataBaseConnector* dbConnector;

    AddNewResource* newResource;

    QString currentEmployee;


};

#endif // PRODUCTIONORDER_H
