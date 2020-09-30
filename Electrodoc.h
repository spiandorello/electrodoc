#ifndef ELECTRODOC_H
#define ELECTRODOC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Electrodoc; }
QT_END_NAMESPACE

class Electrodoc : public QWidget
{
    Q_OBJECT

public:
    Electrodoc(QWidget *parent = nullptr);
    ~Electrodoc();

private:
    Ui::Electrodoc *ui;
};
#endif // ELECTRODOC_H
