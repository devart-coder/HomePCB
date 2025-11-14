#include "graphicsviewr.h"

GraphicsViewer::GraphicsViewer(QGraphicsScene *scene, QWidget *pwdg)
    : QGraphicsView(scene,pwdg){
    scene->addRect(100,100,100,100);
    scene->setBackgroundBrush(QBrush(Qt::GlobalColor::darkGray));
    QPainter* painter = new QPainter();
    scene->drawBackground( painter,QRectF(100,100,100,100));
}
