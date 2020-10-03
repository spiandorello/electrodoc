#include "Electrodoc.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Electrodoc electrodocScreen;
    electrodocScreen.show();
    return app.exec();
}
