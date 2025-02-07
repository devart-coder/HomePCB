#ifndef CROSSARROWS_H
#define CROSSARROWS_H
#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPoint>
#include <QStatusBar>
#include <QBrush>
#include <QColor>
class CrossArrows : public QObject, public QGraphicsRectItem
{
private:
    Q_OBJECT
    QRectF circle = QRectF();
    QBrush circleBrush = QBrush(Qt::GlobalColor::red);
    bool circleDrawFlag = false;
public:
    CrossArrows(const QRectF& rectangle, QGraphicsItem *parent = nullptr);
public:
    QRectF boundingRect() const override;
    QPointF getCenter() const;
    qreal getDiameter() const;
    QColor getColor()	const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void drawCircle(bool flag);
    bool isCircleDrawed();
signals:
    void colorChanged(const QColor&);
public slots:
    void setCircleDiameter(double diameter);
    void setColor(const QColor& color);
};

#endif // CROSSARROWS_H
