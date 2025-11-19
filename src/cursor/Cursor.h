#ifndef CURSOR_H
#define CURSOR_H
#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPoint>
#include <QStatusBar>
#include <QBrush>
#include <QColor>
#include <QPen>
#include <SpotF.h>
#include <QLine>
#include <QList>
class Cursor : public QObject, public QGraphicsRectItem
{
private://Fields
    Q_OBJECT
    SpotF* spot_v;
    QList<QLine> lines;
public://Constructors
    Cursor( const QRectF& rectangle,
            const QPen& pen = QPen (Qt::GlobalColor::white,2),
            const QBrush& brush = QBrush(Qt::GlobalColor::red),
            QGraphicsItem *parent = nullptr) noexcept;
public://Methods
    QRectF boundingRect();
    SpotF* spot();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void colorChanged(const QColor&);
};

#endif // CURSOR_H
