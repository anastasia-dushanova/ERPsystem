#ifndef TECHNOLOGICALCARD_H
#define TECHNOLOGICALCARD_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class TechnologicalCard;
}

class TechnologicalCard : public QWidget
{
    Q_OBJECT

public:
    explicit TechnologicalCard(QWidget *parent = nullptr);
    ~TechnologicalCard();

    void addProductInfo(QString name, int inReserve);

    void addNewResource(QString product, QString material, int count);

    void deleteResource();

    QList<QPair<QString, QString>> getProducts();

    QList<QPair<QString, QString>> getMaterials();


private:
    Ui::TechnologicalCard *ui;
};

#endif // TECHNOLOGICALCARD_H
