#include "CNC_Simulator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CNC_Simulator w;
    w.show();
    return a.exec();
}
