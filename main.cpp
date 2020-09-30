#include "Electrodoc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Electrodoc w;
    w.show();
    return a.exec();
}
