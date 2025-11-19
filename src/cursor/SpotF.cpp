#include "SpotF.h"

SpotF::SpotF(const QRectF &rect, const QPen &pen, const QBrush &brush, QGraphicsItem *parent) noexcept
    :QGraphicsRectItem(parent)
{
    this->setRect(rect);
    this->setPen(pen);
    this->setBrush(brush);
}
QRectF SpotF::boundingRect()
{
    return rect();
}
QPainterPath SpotF::shape() const noexcept
{
    return this->shape();
}
qreal SpotF::getDiameter() const noexcept
{
    return this->rect().width();
}
void SpotF::setDiameter(double d)
{
    auto r = this->rect();
    this->setRect(r.center().x()-d/2, r.center().y()-d/2, d, d);
}
QColor SpotF::getColor() const noexcept
{
    return this->brush().color();
}
void SpotF::setColor(const QColor &c)
{
    this->setBrush(QBrush(c));
}
void SpotF::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();

    //drawEmptyCircle
    painter->setPen(this->pen());
    painter->drawEllipse( rect().center(), rect().width()/2, rect().height()/2 );

    //drawFillCircle
    painter->setBrush(this->brush());
    painter->setOpacity(0.5);
    painter->drawEllipse( rect().center(), rect().width()/2, rect().height()/2 );
    painter->restore();
}
