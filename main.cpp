#include "PCBApplication.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePCBMain homePCB;
    homePCB.show();
    return a.exec();
}
