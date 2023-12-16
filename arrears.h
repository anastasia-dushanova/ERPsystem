#ifndef ARREARS_H
#define ARREARS_H

#include <QWidget>

namespace Ui {
class Arrears;
}

class Arrears : public QWidget
{
    Q_OBJECT

public:
    explicit Arrears(QWidget *parent = nullptr);
    ~Arrears();

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::Arrears *ui;
};

#endif // ARREARS_H
