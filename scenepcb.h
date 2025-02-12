#ifndef SCENEPCB_H
#define SCENEPCB_H
#include <QGraphicsScene>
#include <QVector>
#include <QLine>
#include <QStack>
#include "crossarrows.h"
#include "linepcb.h"
class ScenePCB : public QGraphicsScene{
private:
    Q_OBJECT
    QVector<QLine> backgroundLines = QVector<QLine>();
    QStack<QGraphicsItem*> linesStack  = QStack<QGraphicsItem*> ();
    CrossArrows* crossArrows = new CrossArrows(QRect(0,0,100,100));
    LinePCB* lineCreation(const QPointF& start, const QPointF& end);

    int gridOffset = 100;
    bool lineCheckFlag = false;
    bool firstMouseClickChecker = false;
    void moveCrossArrows(QGraphicsSceneMouseEvent *event);
public:
    ScenePCB(const QRectF& rect, QObject* parent = nullptr);
    ScenePCB (qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);

    // QGraphicsScene interface
    void drawBackground(QPainter *painter, const QRectF &rect);
    CrossArrows *getCrossArrows() const;
    void setCrossArrows(CrossArrows *newCrossArrows);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void getCrossArrowsPosition(const QPointF& pos);
    void itemAppented(QGraphicsItem* item);
public slots:
    void getLineCheckFlag(bool flag);
    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // SCENEPCB_H
