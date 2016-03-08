#include "MyMainWD.h"
#include <iostream>
#include <QApplication>

int main(int argc , char **argv)
{
    QApplication app(argc, argv);
    MyMainWD m;
    m.show();

    return app.exec();
}
