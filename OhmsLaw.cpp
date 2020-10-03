#include "OhmsLaw.h"
#include "ui_OhmsLaw.h"

#include <QtMath>
#include <QMessageBox>
#include <QRegExpValidator>

OhmsLaw::OhmsLaw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OhmsLaw)
{
    ui->setupUi(this);

    ui->voltageInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->voltageInput));
    ui->resInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->resInput));
    ui->currentInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->currentInput));
    ui->powerInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->powerInput));
}

double OhmsLaw::calcResistence(QString voltage, QString current, QString power) {

    if (!voltage.isEmpty() && !current.isEmpty()) {
        return voltage.toDouble() / current.toDouble();
    }


    return 0;
}

double OhmsLaw::calcVoltage(QString resistence, QString current, QString power) {

    if (!power.isEmpty() && !current.isEmpty()) {
        return power.toDouble() / current.toDouble();
    }

    if (!power.isEmpty() && !resistence.isEmpty()) {
        return qSqrt(power.toDouble() * resistence.toDouble());
    }

    return resistence.toDouble() * current.toDouble();
}

double OhmsLaw::calcCurrent(QString voltage, QString resistence, QString power) {

    if (!voltage.isEmpty() && !resistence.isEmpty()) {
        return power.toDouble() / voltage.toDouble();
    }

    if (!power.isEmpty() && !resistence.isEmpty()) {
        return qSqrt(power.toDouble() / resistence.toDouble());
    }

    return voltage.toDouble() / resistence.toDouble();
}


double OhmsLaw::calcPower(QString voltage, QString resistence, QString current) {

    if (!voltage.isEmpty() && !resistence.isEmpty()) {
        return qPow(voltage.toDouble(), 2) / resistence.toDouble();
    }

    if (!resistence.isEmpty() && !current.isEmpty()) {
        return resistence.toDouble() * qPow(current.toDouble(), 2);
    }

    return voltage.toDouble() * current.toDouble();
}


void OhmsLaw::on_calc_clicked()
{
    QString power = ui->powerInput->text();
    QString voltage = ui->voltageInput->text();
    QString current = ui->currentInput->text();
    QString resistence = ui->resInput->text();

    if (voltage.isEmpty() && resistence.isEmpty() && current.isEmpty() && power.isEmpty()) {
        return;
    }

    if (voltage.isEmpty()) {
        if ((!resistence.isEmpty() && !current.isEmpty()) || (!power.isEmpty() && !current.isEmpty()) || (!power.isEmpty() && !resistence.isEmpty())) {
            ui->voltageInput->setText(QString::number(calcVoltage(resistence, current, power)));
        }
    }

    if (current.isEmpty()) {
        if ((!voltage.isEmpty() && !resistence.isEmpty()) || (!power.isEmpty() && !resistence.isEmpty()) || (!power.isEmpty() && !voltage.isEmpty())) {
            ui->currentInput->setText(QString::number(calcCurrent(voltage, resistence, power)));
        }
    }


    if (resistence.isEmpty()) {
        if ((!voltage.isEmpty() && !current.isEmpty()) || (!power.isEmpty() && !current.isEmpty()) || (!power.isEmpty() && !voltage.isEmpty())) {
            ui->resInput->setText(QString::number(calcResistence(voltage, current, power)));
        }
    }

    if (power.isEmpty()) {
        ui->powerInput->setText(QString::number(calcPower(voltage, resistence, current)));
    }
}


OhmsLaw::~OhmsLaw()
{
    delete ui;
}
