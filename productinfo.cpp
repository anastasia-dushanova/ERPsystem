#include "productinfo.h"

ProductInfo::ProductInfo(){ }

ProductInfo::ProductInfo(int productId, QString name, QString unitMeasure, int productType, int costPrice, int inStock, int inReserve, int available)
    :productId(productId), name(name), unitMeasure(unitMeasure), productType(productType), costPrice(costPrice), inStock(inStock), inReserve(inReserve), available(available)
{

}

ProductInfo::ProductInfo(int productId, QString name, QString unitMeasure, int inStock, int costPrice)
    :productId(productId), name(name), unitMeasure(unitMeasure), inStock(inStock), costPrice(costPrice)
{

}

