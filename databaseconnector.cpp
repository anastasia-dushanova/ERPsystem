#include "databaseconnector.h"

DataBaseConnector::DataBaseConnector(QObject* parent) : QObject(parent)
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QCoreApplication::applicationDirPath() + "/db_name.db");
//    qDebug() << QCoreApplication::applicationDirPath();

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

//    if(selectQ.lastError().text() == " ")
//        qDebug() << selectQ.lastError().text();

    int roleId{-1};
    if(selectQ.first())
        roleId = selectQ.value(0).toInt();

    return roleId;
}

int DataBaseConnector::getProductInReserve(){

    QSqlQuery selectQ;
    selectQ.prepare("SELECT in_reserve "
                    "FROM product "
                    "WHERE name = 'ГП1'; ");
    selectQ.exec();
    int inStock{-1};
    if(selectQ.first()){
        inStock = selectQ.value(0).toInt();
    }
    return inStock;
}

QList<ProductInfo> DataBaseConnector::getProductInfo()
{
    QSqlQuery selectQ;
    selectQ.prepare("SELECT product_id, name, unit_measure, product_type, cost_price, in_stock, in_reserve, available "
                    "FROM product; ");

    selectQ.exec();

    QList<ProductInfo> list;
    while(selectQ.next()){
        ProductInfo info(selectQ.value(0).toInt(),
                        selectQ.value(1).toString(),
                        selectQ.value(2).toString(),
                        selectQ.value(3).toInt(),
                        selectQ.value(4).toInt(),
                        selectQ.value(5).toInt(),
                        selectQ.value(6).toInt(),
                        selectQ.value(7).toInt());
        list.append(info);
    }
    return list;
}

QList<ProductInfo> DataBaseConnector::getMaterialInfo()
{
    QSqlQuery selectQ;
    selectQ.prepare("SELECT material_id, name, unit_measure, count_m, cost_price "
                    "FROM material; ");
    selectQ.exec();

    QList<ProductInfo> list;
    while(selectQ.next()){
        ProductInfo info(selectQ.value(0).toInt(),
                         selectQ.value(1).toString(),
                         selectQ.value(2).toString(),
                         selectQ.value(3).toInt(),
                         selectQ.value(4).toInt());

        list.append(info);
    }
    return list;
}

int DataBaseConnector::considerProductionOrder(QString currentEmployee,
                                               QString date_registration,
                                               QString date_entrance,
                                               QString foreman,
                                               QString product)
{
    QSqlQuery selectPr;
    selectPr.prepare("SELECT product_id FROM product WHERE name = :product; ");
    selectPr.bindValue(":product", product);
    selectPr.exec();

    int product_id{-1};
    if(selectPr.next())
        product_id = selectPr.value(0).toInt();

    QSqlQuery selectEm;
    selectEm.prepare("SELECT employee_id FROM employee WHERE name = :currentEmployee; ");
    selectEm.bindValue(":currentEmployee", currentEmployee);
    selectEm.exec();

    int employee_id{-1};
    if(selectEm.next())
        employee_id = selectEm.value(0).toInt();

    QSqlQuery insertQ;
    insertQ.prepare("INSERT INTO production_order(employee_id, product_id, date_registration, date_entrance, foreman) "
                    "VALUES (:employee_id, :product_id, :date_registration, :date_entrance, :foreman)"
                    "RETURNING production_order_id; ");
    insertQ.bindValue(":employee_id", employee_id);
    insertQ.bindValue(":product_id", product_id);
    insertQ.bindValue(":date_registration", date_registration);
    insertQ.bindValue(":date_entrance", date_entrance);
    insertQ.bindValue(":foreman", foreman);

    insertQ.exec();

    int id{-1};
    if(insertQ.next())
        id = insertQ.value(0).toInt();

    if(!insertQ.lastError().text().isEmpty())
        qDebug() << insertQ.lastError().text();

    return id;
}

int DataBaseConnector::updateMaterials(QList<QPair<QString, QString> > list)
{
    int total{0};
    for(int i = 0; i < list.size(); ++i){
        QSqlQuery update;
        QString name = list[i].first;
//        qDebug() << name;
        QString count = list[i].second;
//        qDebug() << count;
        update.prepare("UPDATE material "
                        "SET count_m = (SELECT count_m FROM material WHERE name = :name) - :count "
                        "WHERE name = :name; ");

        update.bindValue(":name", name);
        update.bindValue(":count", count);
        update.exec();

        QSqlQuery select;
        select.prepare("SELECT cost_price * :count "
                       "FROM material "
                       "WHERE name = :name; ");

        select.bindValue(":count", count);
        select.bindValue(":name", name);
        select.exec();

        if(select.next()){
            total += select.value(0).toInt();
            qDebug() << select.value(0).toInt();
        }

    }
    return total;
}

int DataBaseConnector::considerSalesOrder(QString employee, QString date_reg, QString date_ship, QString total)
{
    QSqlQuery insertQ;
    insertQ.prepare("WITH emp AS (SELECT employee_id AS id FROM employee WHERE name = :employee), "
                          "contr AS (SELECT contact_person_id AS id FROM contact_person WHERE name = 'Иванов Иван Иванович') "
                   "INSERT INTO sales_order(employee_id, contact_person_id, contract_id, date_registration, date_shipment, total_m) "
                   "SELECT emp.id, contr.id, 1, :date_reg, :date_ship, :total "
                   "FROM emp, contr "
                   "RETURNING sales_order_id; ");

    insertQ.bindValue(":employee", employee);
    insertQ.bindValue(":date_reg", date_reg);
    insertQ.bindValue(":date_ship", date_ship);
    insertQ.bindValue(":total", total);
    insertQ.exec();

    if(!insertQ.lastError().text().isEmpty())
        qDebug() << insertQ.lastError().text();

    int id{-1};
    if(insertQ.next())
        id = insertQ.value(0).toInt();

    return id;
}
