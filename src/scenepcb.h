#ifndef SCENEPCB_H
#define SCENEPCB_H
#include <QGraphicsScene>
#include <QVector>
#include <QLine>
#include <QStack>
#include "Cursor.h"
#include "linepcb.h"
#include <QGraphicsRectItem>
class ScenePCB : public QGraphicsScene{
private:
    //fields
    Q_OBJECT
    QGraphicsRectItem* space;
    QList<QLine> backgroundLines;
    QStack<QGraphicsItem*> linesStack;
    Cursor* cursor_v;

    int gridOffset = 100;
    bool lineCheckFlag = false;
    bool firstMouseClickChecker = false;
    void moveCrossArrows(QGraphicsSceneMouseEvent *event);
public:
    //methods
    ScenePCB(const QRectF& rect, const QBrush &background, QObject* parent = nullptr);
    ScenePCB (qreal x, qreal y, qreal width, qreal height, const QBrush &background, QObject *parent = nullptr);

    // QGraphicsScene interface
    void drawBackground(QPainter *painter, const QRectF &rect);
    Cursor* cursor() const;
    void setCursor(Cursor *newCursor);
    LinePCB* lineCreation(const QPointF& start, const QPointF& end);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void getCursorPosition(const QPointF& pos);
    void itemAppented(QGraphicsItem* item);
public slots:
    void getLineCheckFlag(bool flag);
    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // SCENEPCB_H
