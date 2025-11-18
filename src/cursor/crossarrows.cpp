#include "crossarrows.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
CrossArrows::CrossArrows(const QRectF& rectangle, const QPen& pen, const QBrush& brush, QGraphicsItem* parent) noexcept
    :spot_v(new SpotF(rectangle))
    ,QGraphicsRectItem(rectangle)
{
    this->spot()->hide();
    this->setRect(rectangle);
    this->setPen(pen);
    this->setBrush(brush);
}
QRectF CrossArrows::boundingRect() const
{
    return rect();
}
 SpotF* CrossArrows::spot()
{
    return this->spot_v;
}
void CrossArrows::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter->setPen(pen());
    if(spot()->isVisible()){
        spot()->paint(painter,option,widget);
    }
    //drawCrossLinesInsideSpot
    painter->drawLine( rect().height()/2, 0, rect().height()/2, rect().bottom());
    painter->drawLine( 0, rect().width()/2, rect().right(), rect().width()/2);
}
