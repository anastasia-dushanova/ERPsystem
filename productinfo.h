#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <QString>

class ProductInfo
{
public:
    ProductInfo();
    ProductInfo(int productId,
                QString name,
                QString unitMeasure,
                int productType,
                int costPrice,
                int inStock,
                int inReserve,
                int available);

    ProductInfo(int productId,
                QString name,
                QString unitMeasure,
                int inStock,
                int costPrice);

    ~ProductInfo() {}

    void setProductId(int id) { productId = id; }
    void setName(QString name) { this->name = name; }
    void setUnitMeasure(QString unit) { unitMeasure = unit; }
    void setProductType(int produceType) { this->productType = produceType; }
    void setCostPrice(int costPrice) { this->costPrice = costPrice; }
    void setInStock(int inStock) { this->inStock = inStock; }
    void setInReserve(int inReserve) { this->inReserve = inReserve; }
    void setAvailable(int available) { this->available = available; }

    int getProductId() { return productId; }
    QString getName() {  return name; }
    QString getUnitMeasure() { return unitMeasure; }
    int getProductType() { return productType; }
    int getCostPrice() { return costPrice; }
    int getInStock() { return inStock; }
    int getInReserve() { return inReserve; }
    int getAvailable() { return available; }



private:
    int productId;
    QString name;
    QString unitMeasure;
    int productType;
    int costPrice;
    int inStock;
    int inReserve;
    int available;
};

#endif // PRODUCTINFO_H
