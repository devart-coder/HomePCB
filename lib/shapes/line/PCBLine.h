#ifndef LINEPCB_H
#define LINEPCB_H

#include <QGraphicsLineItem>
#include <QPointF>
#include <QLineF>
#include <QPen>
#include <QObject>
#include "PCBLineSettings.h"
class LinePCB : public QGraphicsLineItem , public QObject{
private:
    QPen linePen = QPen();
    LinePCBPropertyDialog* linePropertyDialog = new LinePCBPropertyDialog();
    QString lineToolTip ;
    void dialogInitialize();
public:
    LinePCB(const QPointF& startPoint,const QPointF& endPoint);
    LinePCB(int x1, int y1, int x2, int y2);

    // QGraphicsItem interface
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    LinePCBPropertyDialog *getLinePropertyDialog() const;
    QColor getColor();
    // QGraphicsItem interface
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    // QGraphicsItem interface
protected:
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    static bool getFirstMouseChecker() ;
    static void setFirstMouseChecker(bool newFirstMouseClecked);

public slots:
    void setColor(const QColor& colorName );
    void setDiameter(int d);
};

#endif // LINEPCB_H
