#include "crossarrows.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
CrossArrows::CrossArrows(const QRectF &rectangle, QGraphicsItem* parent)
    :circle(rectangle),QGraphicsRectItem(rectangle){
}

QRectF CrossArrows::boundingRect() const
{
    return rect();
}
QPointF CrossArrows::getCenter() const
{
    return circle.center();
}
qreal CrossArrows::getDiameter() const
{
    return circle.width();
}
QColor CrossArrows::getColor() const
{
    return circleBrush.color();
}
void CrossArrows::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    if(circleDrawFlag){
        painter->save();
        painter->setBrush(circleBrush);
        painter->setOpacity(0.5);
        painter->drawEllipse(rect().center(),circle.width()/2,circle.height()/2);
        painter->restore();
    }
    painter->setPen(QPen(Qt::GlobalColor::white,2));
    if(circleDrawFlag)
        painter->drawEllipse( rect().center(),circle.width()/2,circle.height()/2);
    painter->drawLine( rect().height()/2,0,rect().height()/2,rect().bottom());
    painter->drawLine(0,rect().width()/2,rect().right(),rect().width()/2);
}
void CrossArrows::drawCircle(bool flag)
{
    circleDrawFlag = flag;
}
bool CrossArrows::isCircleDrawed()
{
    return circleDrawFlag;
}
void CrossArrows::setCircleDiameter(double diameter)
{
    circle.setWidth(diameter);
    circle.setHeight(diameter);
    rect().setWidth(qMax(diameter,rect().width()));
    rect().setWidth(qMax(diameter,rect().height()));
    update();
}
void CrossArrows::setColor(const QColor &color)
{
    circleBrush.setColor(color);
    update();
    emit colorChanged(color);
}
