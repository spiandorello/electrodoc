#include "Electrodoc.h"
#include "ui_Electrodoc.h"

Electrodoc::Electrodoc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Electrodoc)
{
    ui->setupUi(this);

    ui->mainStack->insertWidget(1, &OhmsLawScreen);
}

Electrodoc::~Electrodoc()
{
    delete ui;
}

void Electrodoc::on_ohmsLawMenuBtn_clicked()
{
    ui->mainStack->setCurrentIndex(1);
}
