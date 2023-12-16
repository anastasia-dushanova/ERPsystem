#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include <QWidget>
#include <QDebug>
#include <salesorder.h>

namespace Ui {
class Accounting;
}

class Accounting : public QWidget
{
    Q_OBJECT

public:
    explicit Accounting(QWidget *parent = nullptr);
    ~Accounting();

public slots:
    void setCurrentEmployee(QString curr) { this->currentEmployee = curr; }


signals:
    void consider();

private slots:

    void on_pushButton_consider_clicked();

private:
    Ui::Accounting *ui;

    QString currentEmployee;
};

#endif // ACCOUNTING_H
