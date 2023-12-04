#ifndef TECHNOLOGICALCARD_H
#define TECHNOLOGICALCARD_H

#include <QWidget>

namespace Ui {
class TechnologicalCard;
}

class TechnologicalCard : public QWidget
{
    Q_OBJECT

public:
    explicit TechnologicalCard(QWidget *parent = nullptr);
    ~TechnologicalCard();

private:
    Ui::TechnologicalCard *ui;
};

#endif // TECHNOLOGICALCARD_H
