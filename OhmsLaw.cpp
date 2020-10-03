#include "OhmsLaw.h"
#include "ui_OhmsLaw.h"

#include <QtMath>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QDebug>

OhmsLaw::OhmsLaw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OhmsLaw)
{
    ui->setupUi(this);

    ui->voltageInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->voltageInput));
    ui->resInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->resInput));
    ui->currentInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->currentInput));
    ui->powerInput->setValidator(new QRegExpValidator(QRegExp("^[\\d.?!]+$"), ui->powerInput));

    resState = false;
    powerState = false;
    voltageState = false;
    currentState = false;
}

double OhmsLaw::calcResistence(QString voltage, QString current, QString power) {

    if (!power.isEmpty() && !current.isEmpty()) {
        return power.toDouble() / qPow(current.toDouble(), 2);
    }

    if (!power.isEmpty() && !voltage.isEmpty()) {
        return qPow(voltage.toDouble(), 2) / power.toDouble();
    }


    return voltage.toDouble() / current.toDouble();
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

    if (!voltage.isEmpty() && !power.isEmpty()) {
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


    if ((resState != resistence.toDouble() && currentState != current.toDouble())) {
        ui->voltageInput->setText(QString::number(calcVoltage(resistence, current, power)));

        resState = resistence.toDouble();
        powerState = power.toDouble();
        voltageState = voltage.toDouble();
        currentState = current.toDouble();
        return;
    }


    if ((voltageState != voltage.toDouble() && resState != resistence.toDouble())) {
        ui->currentInput->setText(QString::number(calcCurrent(voltage, resistence, power)));

        resState = resistence.toDouble();
        powerState = power.toDouble();
        voltageState = voltage.toDouble();
        currentState = current.toDouble();
        return;
    }


    if ((voltageState != voltage.toDouble() && currentState != current.toDouble())) {
        ui->resInput->setText(QString::number(calcResistence(voltage, current, power)));

        resState = resistence.toDouble();
        powerState = power.toDouble();
        voltageState = voltage.toDouble();
        currentState = current.toDouble();
        return;
    }

//    if (power.isEmpty()) {
//        ui->powerInput->setText(QString::number(calcPower(voltage, resistence, current)));
//    }

}


OhmsLaw::~OhmsLaw()
{
    delete ui;
}
