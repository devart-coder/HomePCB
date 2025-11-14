#include "gcodewidget.h"
#include "linepcb.h"
#include <QDebug>

GCodeWidget::GCodeWidget(QWidget *parent)
    : QWidget{parent}
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
        QString gcomand = "G1";
        auto xPos = linePCB->line().p2().x();
        auto yPos = linePCB->line().p2().y();
        if(treeWidget->children().isEmpty()){
            gcomand = "G0";
            xPos = linePCB->line().p1().x();
            yPos = linePCB->line().p1().y();
        }
        QString xPosString = " X" + QString::number(xPos);
        QString yPosString = " Y" + QString::number(yPos);

        auto color = linePCB->getColor();
        // if()
        qDebug() << color.name();
        treeWidgetItem->setText( 0, colorNames.value(color.name()));
        treeWidgetItem->setText( 1, "Line");
        treeWidgetItem->setText( 2, gcomand + xPosString + yPosString );
    }
}
void GCodeWidget::deleteShape(QGraphicsItem *item)
{
    //TODO::Implementation
}
