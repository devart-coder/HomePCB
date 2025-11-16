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

class CrossArrows : public QObject, public QGraphicsRectItem
{
private://Fields
    Q_OBJECT
    bool spotVisible = false;
    std::unique_ptr<QRectF> spot;
public://Constructors
    CrossArrows( const QRectF& rectangle,
                 const QPen& pen = QPen (Qt::GlobalColor::white,2),
                 const QBrush& brush = QBrush(Qt::GlobalColor::red),
                 QGraphicsItem *parent = nullptr);
public://Methods
    QRectF boundingRect() const override;
    QPointF getSpotCenter() const;
    qreal getSpotDiameter() const;
    QColor getSpotColor()	const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool spotIsDrawed() const;
signals:
    void colorChanged(const QColor&);
public slots:
    void spotVisionToogle();
    void setSpotDiameter(double diameter);
    void setSpotColor(const QColor& color);
};

#endif // CROSSARROWS_H
