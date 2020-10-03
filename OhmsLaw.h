#ifndef OHMSLAW_H
#define OHMSLAW_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class OhmsLaw;
}

class OhmsLaw : public QWidget
{
    Q_OBJECT

public:
    explicit OhmsLaw(QWidget *parent = nullptr);
    double calcResistence(QString voltage, QString current, QString power);
    double calcVoltage(QString resistence, QString current, QString power);
    double calcCurrent(QString voltage, QString resistence, QString power);
    double calcPower(QString voltage, QString resistence, QString current);
    ~OhmsLaw();

private slots:
    void on_calc_clicked();


private:
    Ui::OhmsLaw *ui;
    double resState;
    double powerState;
    double voltageState;
    double currentState;
};

#endif // OHMSLAW_H
