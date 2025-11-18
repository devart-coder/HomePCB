#ifndef CROSSARROWS_H
#define CROSSARROWS_H
#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPoint>
#include <QStatusBar>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <SpotF.h>
class CrossArrows : public QObject, public QGraphicsRectItem
{
private://Fields
    Q_OBJECT
    SpotF* spot_v;
public://Constructors
    CrossArrows( const QRectF& rectangle,
                 const QPen& pen = QPen (Qt::GlobalColor::white,2),
                 const QBrush& brush = QBrush(Qt::GlobalColor::red),
                 QGraphicsItem *parent = nullptr) noexcept;
public://Methods
    QRectF boundingRect() const override;
    SpotF* spot();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void colorChanged(const QColor&);
};

#endif // CROSSARROWS_H
