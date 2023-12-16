#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QObject>
#include <QCoreApplication>

#include <productinfo.h>

class DataBaseConnector : public QObject
{
    Q_OBJECT
public:


    DataBaseConnector(QObject* parent = nullptr);
    ~DataBaseConnector();

    int getRole(QString login, QString password);

    int getProductInReserve();

    QList<ProductInfo> getProductInfo();
    QList<ProductInfo> getMaterialInfo();

    int considerProductionOrder(QString currentEmployee,
                                QString date_registration,
                                QString date_entrance,
                                QString foreman,
                                QString product);

    int updateMaterials(QList<QPair<QString, QString>> list);

    int considerSalesOrder(QString employee, QString date_reg, QString date_ship, QString total);

};

#endif // DATABASECONNECTOR_H
