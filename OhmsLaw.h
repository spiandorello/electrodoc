#ifndef OHMSLAW_H
#define OHMSLAW_H

#include <QWidget>

namespace Ui {
class OhmsLaw;
}

class OhmsLaw : public QWidget
{
    Q_OBJECT

public:
    explicit OhmsLaw(QWidget *parent = nullptr);
    ~OhmsLaw();

private slots:
    void on_calc_clicked();

private:
    Ui::OhmsLaw *ui;
};

#endif // OHMSLAW_H
