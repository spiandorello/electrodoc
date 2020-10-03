#include "OhmsLaw.h"
#include "ui_OhmsLaw.h"

#include <QtMath>
#include <QRegExpValidator>

OhmsLaw::OhmsLaw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OhmsLaw)
{
    ui->setupUi(this);

    ui->voltageInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->resInput));
    ui->resInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->resInput));
    ui->currentInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->resInput));
}

OhmsLaw::~OhmsLaw()
{
    delete ui;
}

void OhmsLaw::on_calc_clicked()
{
    QString voltage = ui->voltageInput->text();
    QString resistence = ui->resInput->text();
    QString current = ui->currentInput->text();

    if (voltage.isEmpty() && resistence.isEmpty() && current.isEmpty()) {
        return;
    }
}
