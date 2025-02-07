#include "linepcb.h"
#include <QPen>
#include <QBrush>
#include <QDebug>
#include <QPainter>
#include <QCursor>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsSceneHoverEvent>
#include <QKeyEvent>
#include "linepcbpropertydialog.h"
#include <QDoubleSpinBox>

LinePCBPropertyDialog *LinePCB::getLinePropertyDialog() const
{
    return linePropertyDialog;
}
QColor LinePCB::getColor()
{
    return linePen.color();
}
void LinePCB::setDiameter(int d)
{
    linePen.setWidth(d);
}
void LinePCB::dialogInitialize()
{
    linePropertyDialog->setStartPoint(line().p1());
    linePropertyDialog->setEndPoint(line().p2());
    linePropertyDialog->setWidthLine(linePen.width());
}
LinePCB::LinePCB(const QPointF &startPoint, const QPointF &endPoint)
    :QGraphicsLineItem(QLineF(startPoint,endPoint)),QObject()
{
    setFlags(QGraphicsLineItem::ItemIsSelectable | QGraphicsLineItem::ItemIsFocusable);
    setAcceptHoverEvents(true);
    auto v = linePropertyDialog->getLinePropertiesVector();
    for(int i=0; i!=v.size(); ++i ){
        switch(i){
            case linePropertyDialog->STARTXPOSITION:
                v[i]->setValue(line().p1().x());
                break;
            case linePropertyDialog->STARTYPOSITION:
                v[i]->setValue(line().p1().y());
                break;
            case linePropertyDialog->ENDXPOSITION:
                v[i]->setValue(line().p2().x());
                break;
            case linePropertyDialog->ENDYPOSITION:
                v[i]->setValue(line().p2().y());
                break;
        }
    }
    linePen.setCapStyle(Qt::RoundCap);
    connect(linePropertyDialog,&LinePCBPropertyDialog::startXPositionChanged,[this](double value){
        setLine(value, line().p1().y(), line().p2().x(), line().p2().y());
    });
    connect(linePropertyDialog,&LinePCBPropertyDialog::startYPositionChanged,[this](double value){
        setLine(line().p1().x(), value, line().p2().x(), line().p2().y());
    });
    connect(linePropertyDialog,&LinePCBPropertyDialog::endXPositionChanged,[this](double value){
        setLine(line().p1().x(), line().p1().y(), value, line().p2().y());
    });
    connect(linePropertyDialog,&LinePCBPropertyDialog::endYPositionChanged,[this](double value){
        setLine(line().p1().x(), line().p1().y(), line().p2().x(), value);
    });
    connect(linePropertyDialog,&LinePCBPropertyDialog::widthChanged,[this](double value){
        linePen.setWidth(value);
        update();
    });
    connect(linePropertyDialog,&LinePCBPropertyDialog::colorChange, [this](auto colorName){
        setColor(colorName);
    });
}
LinePCB::LinePCB(int x1, int y1, int x2, int y2)
    :QGraphicsLineItem(QLineF(QPointF(x1,y1),QPointF(x2,y2)))
{
    LinePCB(QPointF(x1,y1),QPointF(x2,y2));
}
void LinePCB::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->save();
    if(hasFocus() || isSelected()){
        auto p = QPen();
        p.setCapStyle(Qt::RoundCap);
        p.setColor(Qt::GlobalColor::white);
        p.setWidth(linePen.width()+5);
        painter->setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter->setPen(p);
        painter->drawLine(line().p1(),line().p2());
    }
    painter->restore();
    painter->setPen(linePen);
    painter->drawLine(line().p1(),line().p2());
}
void LinePCB::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    dialogInitialize();
    linePropertyDialog->exec();
}
void LinePCB::focusInEvent(QFocusEvent *event)
{
    grabKeyboard();
    QGraphicsLineItem::focusInEvent(event);
}
void LinePCB::focusOutEvent(QFocusEvent *event)
{
    ungrabKeyboard();
    QGraphicsLineItem::focusOutEvent(event);
}
void LinePCB::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setFocus();
    QGraphicsLineItem::hoverEnterEvent(event);
}
void LinePCB::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    clearFocus();
    QGraphicsLineItem::hoverLeaveEvent(event);
}
void LinePCB::keyPressEvent(QKeyEvent *event)
{
   if(event->key() == Qt::Key_E && event->modifiers() == Qt::ControlModifier){
        dialogInitialize();
        linePropertyDialog->exec();
   }else if (event->key() == Qt::Key_Delete){
        emit destroyed(this);
   }
}
QRectF LinePCB::boundingRect() const
{
    //AddWidthToRedrawLineCorrectly
    auto width = linePen.width();
    int xMin = qMin(line().p1().x(),line().p2().x())-width;
    int yMin = qMin(line().p1().y(),line().p2().y())-width;
    int xMax = qMax(line().p1().x(),line().p2().x())+width;
    int yMax = qMax(line().p2().y(),line().p2().y())+width;
    return QRectF(xMin, yMin, xMax, yMax);
}
void LinePCB::setColor(const QColor &colorName)
{
    linePen.setColor(colorName);
    update();
}
