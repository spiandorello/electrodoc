#include "Electrodoc.h"
#include "ui_Electrodoc.h"

Electrodoc::Electrodoc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Electrodoc)
{
    ui->setupUi(this);
}

Electrodoc::~Electrodoc()
{
    delete ui;
}

