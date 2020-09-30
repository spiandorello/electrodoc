#include "OhmsLaw.h"
#include "ui_OhmsLaw.h"

OhmsLaw::OhmsLaw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OhmsLaw)
{
    ui->setupUi(this);
}

OhmsLaw::~OhmsLaw()
{
    delete ui;
}
