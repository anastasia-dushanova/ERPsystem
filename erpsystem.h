#ifndef ERPSYSTEM_H
#define ERPSYSTEM_H

#include <QMainWindow>
#include <QMessageBox>
#include <databaseconnector.h>
#include <productionorder.h>
#include <salesorder.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ERPsystem; }
QT_END_NAMESPACE

class ERPsystem : public QMainWindow
{
    Q_OBJECT

public:
    enum class Role : int {
        Role_Manager = 1,
        Role_Employee,
        Role_Accounting
    };

    ERPsystem(QWidget *parent = nullptr);
    ~ERPsystem();

signals:
    void newEmployeeProduct(QString);
    void newEmployeeSales(QString);
    void newEmployeeAccounting(QString);

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_exit_clicked();

    void slotConsider();

//    void slotShowSalesOrder();

private:
    Ui::ERPsystem *ui;

    DataBaseConnector* dbConnector;

//    QString currentEmployee;

    void startPorductionOrder();

    void startSalesOrder();

    void startAccounting();

    void clearAndShow();

//    void setCurrentEmloyee(QString login);

//    QString getCurrentEmployee();
};
#endif // ERPSYSTEM_H
