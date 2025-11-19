#include "scenepcb.h"
#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QDebug>
#include <QtMath>
#include "linepcb.h"
#include <QKeyEvent>
ScenePCB::ScenePCB(const QRectF &rect, const QBrush& background, QObject *parent )
    :cursor_v(new Cursor(QRect(0,0,100,100)))
    ,QGraphicsScene(rect,parent)
{
    for(int i=0; i<=rect.right(); i+=gridOffset)
        backgroundLines << QLine( i, 0, i, rect.bottom() ) <<  QLine( 0, i, rect.right(), i );

    space = this->addRect(rect,QPen(QBrush(Qt::GlobalColor::white),2));
    this->addItem(cursor());
    this->setBackgroundBrush(background);
}
ScenePCB::ScenePCB(qreal x, qreal y, qreal width, qreal height, const QBrush& background, QObject *parent)
    :ScenePCB(QRectF(x,y,width,height), background, parent)
{
}
void ScenePCB::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter,rect);
    painter->save();
    painter->setPen(space->pen());
    painter->drawLines(backgroundLines);
    painter->restore();
}
Cursor *ScenePCB::cursor() const
{
    return cursor_v;
}
void ScenePCB::setCursor(Cursor* newCursor)
{
    cursor_v = newCursor;
}
void ScenePCB::moveCrossArrows(QGraphicsSceneMouseEvent *event){
    int cursorWidth = cursor()->boundingRect().width()/2;
    int cursorHeight = cursor()->boundingRect().height()/2;

    int mouseXPos=round((((double)(event->scenePos().x()))/100))*100;
    int mouseYPos=round((((double)(event->scenePos().y()))/100))*100;

    if(this->sceneRect().contains(event->scenePos()) )
        cursor()->setPos( mouseXPos - cursorWidth, mouseYPos - cursorHeight);
    //redrawBackground
    this->invalidate(sceneRect(),QGraphicsScene::BackgroundLayer);
    emit getCursorPosition(QPointF(mouseXPos,mouseYPos));
}
LinePCB* ScenePCB::lineCreation(const QPointF &start, const QPointF &end)
{
    auto line = new LinePCB(start,end);
    line->setColor(cursor()->spot()->getColor());

    // //conections
     connect(line,&LinePCB::destroyed,[=](auto itemPointer){
         //removeItem(dynamic_cast<LinePCB*>(itemPointer));
         firstMouseClickChecker=false;
     });

    //setMaximumValuesForDialog
     for(auto&& v : line->getLinePropertyDialog()->getLinePropertiesVector())
         v->setRange(0,sceneRect().right());

    line->setDiameter(cursor()->spot()->getDiameter());
    linesStack.push_back(line);
    return line;
}
void ScenePCB::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moveCrossArrows(event);
    if(lineCheckFlag && !linesStack.empty()){
        if(auto lineOnScene = dynamic_cast<LinePCB*>(linesStack.top()); lineOnScene){
            auto end = cursor()->scenePos() + cursor()->boundingRect().center();
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
                auto start = cursor()->scenePos() + cursor()->boundingRect().center();
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
