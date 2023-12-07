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
        Role_Employee
    };

    ERPsystem(QWidget *parent = nullptr);
    ~ERPsystem();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::ERPsystem *ui;

    DataBaseConnector* dbConnector;

    void startPorductionOrder();

    void startSalesOrder();
};
#endif // ERPSYSTEM_H
