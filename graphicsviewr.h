#ifndef GRAPHICSVIEWR_H
#define GRAPHICSVIEWR_H
#include <QGraphicsView>

class GraphicsViewer : public QGraphicsView
{
public:
    GraphicsViewer(QGraphicsScene* scene, QWidget* pwdg = 0);
};

#endif // GRAPHICSVIEWR_H
