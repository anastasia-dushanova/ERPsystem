#include "technologicalcard.h"
#include "ui_technologicalcard.h"

TechnologicalCard::TechnologicalCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TechnologicalCard)
{
    ui->setupUi(this);

//    setFixedSize(QSize(1900, 1080));
}

TechnologicalCard::~TechnologicalCard()
{
    delete ui;
}
