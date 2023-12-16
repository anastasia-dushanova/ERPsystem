#ifndef ADDNEWRESOURCE_H
#define ADDNEWRESOURCE_H

#include <QWidget>
#include <QDebug>
#include <QValidator>

namespace Ui {
class AddNewResource;
}

class AddNewResource : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewResource(QWidget *parent = nullptr);
    ~AddNewResource();
signals:
    void addNewResource(QString product, QString material, int count);


private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::AddNewResource *ui;
};

#endif // ADDNEWRESOURCE_H
