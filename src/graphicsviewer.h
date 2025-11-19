#ifndef GRAPHICSVIEWER_H
#define GRAPHICSVIEWER_H
#include <QGraphicsView>
#include "Cursor.h"
class GraphicsViewer : public QGraphicsView
{
public:
    GraphicsViewer (QGraphicsScene *scene, QWidget *parent = nullptr);

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event) override;

    // QGraphicsView interface
protected:
    // void drawBackground(QPainter *painter, const QRectF &rect) override;
};

#endif // GRAPHICSVIEWER_H
