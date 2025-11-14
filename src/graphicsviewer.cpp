#include "graphicsviewer.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWheelEvent>
#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QVBoxLayout>
#include "crossarrows.h"
#include "linepcb.h"
GraphicsViewer::GraphicsViewer(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene,parent){
    setMouseTracking(true);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setCacheMode(QGraphicsView::CacheBackground);
    setDragMode(QGraphicsView::ScrollHandDrag);
    ensureVisible(scene->sceneRect(),50,50);
}
void GraphicsViewer::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y() > 0)
        scale(1.01,1.01);
    else if(event->angleDelta().y() < 0)
        scale(1/1.01,1/1.01);
    QGraphicsView::wheelEvent(event);
}
