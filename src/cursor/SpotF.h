#ifndef SPOTF_H
#define SPOTF_H
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QRectF>
class SpotF : public QGraphicsRectItem
{
public:
    explicit SpotF(const QRectF& rect,
          const QPen& pen = QPen(Qt::GlobalColor::white,2),
          const QBrush& brush = QBrush(Qt::GlobalColor::red),
          QGraphicsItem *parent = nullptr) noexcept;
public:
    //Shared
    QRectF boundingRect() ;
    QPainterPath shape()  			const noexcept;
    qreal getDiameter() 			const noexcept;
    QColor getColor() 				const noexcept;
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public slots:
    void setDiameter(double d);
    void setColor(const QColor& c);
};

#endif // SPOTF_H
