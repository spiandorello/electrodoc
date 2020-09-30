#include "Electrodoc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Electrodoc electrodocScreen;
    electrodocScreen.show();
    return app.exec();
}
