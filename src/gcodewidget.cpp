#include "gcodewidget.h"
#include "linepcb.h"
#include <QDebug>
#include <QStringBuilder>
#include <QGraphicsScene>
GCodeWidget::GCodeWidget(QWidget *parent)
    :QWidget(parent)
    , lines(QVector<QLineF>())
{
    comLineInitialize();

    auto hBox = new QHBoxLayout();
    hBox->addWidget(comLine);
    hBox->addWidget(okButton);

    auto vBox = new QVBoxLayout();
    vBox->addLayout(hBox);
    vBox->addWidget(modelInitialize());
    setLayout(vBox);
}
void GCodeWidget::comLineInitialize()
{
    comLine->setPlaceholderText("Input GCode Command");
    QStringList completeStrings {"G01","G02","G03"};
    auto completer = new QCompleter(completeStrings);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    comLine->setCompleter(completer);

    connect(okButton,&QPushButton::clicked,[this](){
        auto text = comLine->text();
    });
}
QTreeWidget* GCodeWidget::modelInitialize()
{
    treeWidget->setHeaderLabels(QStringList {"Color","Shape","GCommand"});
    treeWidget->setSortingEnabled(false);

    //auto treeWidgetItem = new QTreeWidgetItem(treeWidget);
    //treeWidgetItem->setText(0,"RED");
    //treeWidgetItem->setCheckState(0,Qt::Checked);

    return treeWidget;
}
void GCodeWidget::addShape(QGraphicsItem *item)
{
    if(auto linePCB = dynamic_cast<LinePCB*>(item);linePCB){
        auto treeWidgetItem = new QTreeWidgetItem(treeWidget);
        auto color = linePCB->getColor();
        qreal xPos = 0;
        qreal yPos = 0;
        QString slist = "";
        if(treeWidget->children().size() == 1){
            xPos = linePCB->line().p1().x();
            yPos = linePCB->line().p1().y();
            slist +=  "G0";
        }else {
            xPos = linePCB->line().p2().x();
            yPos = linePCB->line().p2().y();
            slist +=  "G1";
        }
        slist += " X" + QString::number(xPos)
              + " Y" + QString::number(yPos);
        lines.emplace_back( linePCB->line() );

        treeWidgetItem->setText( 0, colorNames.value(color.name()));
        treeWidgetItem->setText( 1, "Line");
        treeWidgetItem->setText( 2, slist);

        connect(linePCB, &LinePCB:: destroyed, [this](auto lineItem){
            if(auto linePCB = dynamic_cast<LinePCB*>(lineItem); linePCB){
                auto ln = linePCB->line();
                auto i = lines.indexOf(linePCB->line());
                treeWidget->takeTopLevelItem(i)->~QTreeWidgetItem();
                lines.removeAt(i);
                linePCB->scene()->removeItem(linePCB);
            }
        });
    }
}
void GCodeWidget::deleteShape(QGraphicsItem *item)
{
    //TODO::Implementation
}
