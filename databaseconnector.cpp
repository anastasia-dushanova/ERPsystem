#include "databaseconnector.h"

DataBaseConnector::DataBaseConnector(QObject* parent) : QObject(parent)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QCoreApplication::applicationDirPath() + "/db_name.db");
    qDebug() << QCoreApplication::applicationDirPath();

    if (!sdb.open()) {
           qDebug() << sdb.lastError().text();
    }else
        qDebug() << "open";

//    QSqlQuery query;
//    query.exec("SELECT employee_id FROM employee;");
//    if(!query.lastError().text().isEmpty())
//        qDebug() << "error "<<query.lastError().text();
}

DataBaseConnector::~DataBaseConnector(){

}

int DataBaseConnector::getRole(QString login, QString password){

    QSqlQuery selectQ;
    selectQ.prepare("SELECT role "
                      "FROM roles "
                      "WHERE login = :login AND password = :password; ");
    selectQ.bindValue(":login", login);
    selectQ.bindValue(":password", password);
    selectQ.exec();

    if(selectQ.lastError().text() == " ")
        qDebug() << selectQ.lastError().text();

    int roleId{-1};
    if(selectQ.first())
        roleId = selectQ.value(0).toInt();

    return roleId;
}
