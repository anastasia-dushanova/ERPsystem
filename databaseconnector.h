#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QObject>
#include <QCoreApplication>

class DataBaseConnector : public QObject
{
    Q_OBJECT
public:


    DataBaseConnector(QObject* parent = nullptr);
    ~DataBaseConnector();

    int getRole(QString login, QString password);

};

#endif // DATABASECONNECTOR_H
