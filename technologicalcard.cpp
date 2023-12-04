#include "technologicalcard.h"
#include "ui_technologicalcard.h"

TechnologicalCard::TechnologicalCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TechnologicalCard)
{
    ui->setupUi(this);
}

TechnologicalCard::~TechnologicalCard()
{
    delete ui;
}
