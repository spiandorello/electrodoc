#ifndef ELECTRODOC_H
#define ELECTRODOC_H

#include <QWidget>

#include "OhmsLaw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Electrodoc; }
QT_END_NAMESPACE

class Electrodoc : public QWidget
{
    Q_OBJECT

public:
    Electrodoc(QWidget *parent = nullptr);
    ~Electrodoc();

private slots:
    void on_ohmsLawMenuBtn_clicked();

private:
    Ui::Electrodoc *ui;
    OhmsLaw OhmsLawScreen;
};
#endif // ELECTRODOC_H
