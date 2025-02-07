#include "homepcbmain.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QRectF>
#include "graphicsviewer.h"
#include "scenepcb.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePCBMain homePCB;
    homePCB.show();
    return a.exec();
}
