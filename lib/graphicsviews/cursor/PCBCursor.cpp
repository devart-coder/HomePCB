#include "PCBCursor.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
Cursor::Cursor(const QRectF& rectangle, const QPen& pen, const QBrush& brush, QGraphicsItem* parent) noexcept
    :spot_v(new SpotF(rectangle))
    ,QGraphicsRectItem(rectangle)
{
    this->spot()->hide();
    this->setRect(rectangle);
    this->setPen(pen);
    this->setBrush(brush);

    lines << QLine(rect().height()/2, 0, rect().height()/2, rect().bottom())
          << QLine(0, rect().width()/2, rect().right(), rect().width()/2);
}
QRectF Cursor::boundingRect()
{
    return this->spot()->rect();
}
 SpotF* Cursor::spot()
{
    return this->spot_v;
}
void Cursor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter->setPen(pen());
    if(spot()->isVisible())
        spot()->paint(painter,option,widget);
    painter->drawLines(lines);
}
