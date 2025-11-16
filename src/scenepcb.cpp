#include "scenepcb.h"
#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QDebug>
#include <QtMath>
#include "linepcb.h"
#include <QKeyEvent>
#include "boolmap.h"
ScenePCB::ScenePCB(const QRectF &rect, QObject *parent )
    :QGraphicsScene(rect,parent) {
    for(int i=0; i<=rect.right(); i+=gridOffset)
        backgroundLines.push_back(QLine(i,0,i,rect.bottom()));

    for(int i=0; i<=rect.bottom(); i+=gridOffset)
        backgroundLines.push_back(QLine(0,i,rect.right(),i));

    //SceneRectVisualization
    this->addRect(rect,QPen(QBrush(Qt::GlobalColor::white),2));
    this->addItem(crossArrows);
    this->setBackgroundBrush(QBrush(Qt::GlobalColor::black));
}
ScenePCB::ScenePCB(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    :QGraphicsScene(x,y,width,height,parent){
    ScenePCB(QRectF(x,y,width,height),parent);
}
void ScenePCB::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter,rect);
    QPen pen = QPen(QBrush(Qt::GlobalColor::white),1);
    for(QLine p : backgroundLines){
        if((p.x2()/gridOffset)%100 == 0 ||( p.y2()/gridOffset)% 100 == 0){
            pen.setWidth(2);
            pen.setColor(Qt::GlobalColor::white);
        }
        else{
            pen.setWidth(1);
            pen.setColor(Qt::GlobalColor::darkGray);
        }
        painter->setPen(pen);
        painter->drawLine(p);
    }
}
CrossArrows *ScenePCB::getCrossArrows() const
{
    return crossArrows;
}
void ScenePCB::setCrossArrows(CrossArrows *newCrossArrows)
{
    crossArrows = newCrossArrows;
}
void ScenePCB::moveCrossArrows(QGraphicsSceneMouseEvent *event){
    int crossArrowsWidth = crossArrows->boundingRect().width()/2;
    int crossArrowsHeight = crossArrows->boundingRect().height()/2;

    int mouseXPos=round((((double)(event->scenePos().x()))/100))*100;
    int mouseYPos=round((((double)(event->scenePos().y()))/100))*100;

    if(this->sceneRect().contains(event->scenePos()) )
        crossArrows->setPos( mouseXPos - crossArrowsWidth, mouseYPos - crossArrowsHeight);
    //redrawBackground
    this->invalidate(sceneRect(),QGraphicsScene::BackgroundLayer);
    //throw event
    emit getCrossArrowsPosition(QPointF(mouseXPos,mouseYPos));
}
LinePCB* ScenePCB::lineCreation(const QPointF &start, const QPointF &end)
{
    auto line = new LinePCB(start,end);
    line->setColor(crossArrows->getSpotColor());

    // //conections
     connect(line,&LinePCB::destroyed,[=](auto itemPointer){
         removeItem(dynamic_cast<LinePCB*>(itemPointer));
         firstMouseClickChecker=false;
     });

    //setMaximumValuesForDialog
     for(auto&& v : line->getLinePropertyDialog()->getLinePropertiesVector())
         v->setRange(0,sceneRect().right());

    line->setDiameter(crossArrows->getSpotDiameter());
    linesStack.push_back(line);
    return line;
}
void ScenePCB::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moveCrossArrows(event);
    if(lineCheckFlag && !linesStack.empty()){
        if(auto lineOnScene = dynamic_cast<LinePCB*>(linesStack.top()); lineOnScene){
            auto end = crossArrows->scenePos() + crossArrows->boundingRect().center();
            lineOnScene->setLine(QLineF(lineOnScene->line().p1(), end));
            lineOnScene->setOpacity(0.5);
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}
void ScenePCB::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        if(event->button() == Qt::MouseButton::LeftButton && lineCheckFlag == true){
            if(firstMouseClickChecker == true){
                if(linesStack.empty())
                    return;
                if(auto lineOnScene = dynamic_cast<LinePCB*>(linesStack.pop()); lineOnScene){
                    lineOnScene->setToolTip(QString {
                                                "( "
                                                + QString::number(lineOnScene->line().p1().x())
                                                + " , "+QString::number(lineOnScene->line().p1().y())
                                                + " ) -> ( "
                                                + QString::number(lineOnScene->line().p2().x())
                                                + " , "
                                                + QString::number(lineOnScene->line().p2().y())
                                                + " )\n"});
                    lineOnScene->setOpacity(1);
                    if(lineOnScene->line().p1() == lineOnScene->line().p2())
                        removeItem(lineOnScene);
                    emit itemAppented(dynamic_cast<QGraphicsItem*>(lineOnScene));
                    update();
                    firstMouseClickChecker=false;
                }
            }//LeftMouseButtonPressedOnce
            else{
                auto start = crossArrows->scenePos() + crossArrows->boundingRect().center();
                auto end = start;
                auto line = lineCreation(start,end);
                addItem(line);
                firstMouseClickChecker=true;
            }//LeftMouseButtonPressedTwice
        }else if (event->button() == Qt::MouseButton::RightButton && firstMouseClickChecker){
            removeItem(linesStack.pop());
            firstMouseClickChecker = false;
            update();
        }
    QGraphicsScene::mouseMoveEvent(event);
}
void ScenePCB::getLineCheckFlag(bool flag)
{
    lineCheckFlag = flag;
}
void ScenePCB::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape  && lineCheckFlag && !linesStack.empty()){
        removeItem(linesStack.pop());
        update();
        firstMouseClickChecker = false;
    }
    QGraphicsScene::keyPressEvent(event);
}
