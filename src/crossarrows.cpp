#include "crossarrows.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
CrossArrows::CrossArrows(const QRectF& rectangle, const QPen& pen, const QBrush& brush, QGraphicsItem* parent)
    :spot(std::make_unique<QRectF>(rectangle))
    ,QGraphicsRectItem(rectangle)
{

    this->setRect(rectangle);
    this->setPen(pen);
    this->setBrush(brush);
}
QRectF CrossArrows::boundingRect() const
{
    return rect();
}
QPointF CrossArrows::getSpotCenter() const
{
    return spot->center();
}

qreal CrossArrows::getSpotDiameter() const
{
    return spot->width();
}
void CrossArrows::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter->setPen(pen());
    if(spotVisible){
        //drawACircle
        painter->save();
        painter->setBrush(brush());
        painter->setOpacity(0.5);
        painter->drawEllipse( rect().center(), spot->width()/2, spot->height()/2 );
        painter->restore();
        //drawLineAroundCircle
        painter->drawEllipse( rect().center(), spot->width()/2, spot->height()/2 );
    }
    //drawCrossLines
    painter->drawLine( rect().height()/2, 0, rect().height()/2, rect().bottom());
    painter->drawLine( 0, rect().width()/2, rect().right(), rect().width()/2);
}
void CrossArrows::spotVisionToogle()
{
    spotVisible = (spotVisible == false) ? true : false;
}
bool CrossArrows::spotIsDrawed() const
{
    return spotVisible;
}
void CrossArrows::setSpotDiameter(double diameter)
{
    spot->setWidth(diameter);
    spot->setHeight(diameter);

    rect().setWidth(qMax(diameter,rect().width()));
    rect().setWidth(qMax(diameter,rect().height()));
    update();
}
void CrossArrows::setSpotColor(const QColor &color)
{
    auto br=this->brush();
    br.setColor(color);
    this->setBrush(br);
    update();
    emit colorChanged(color);
}
QColor CrossArrows::getSpotColor() const
{
    return brush().color();
}
