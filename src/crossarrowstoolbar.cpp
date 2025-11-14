#include "crossarrowstoolbar.h"
#include <QDebug>
CrossArrowToolBar::CrossArrowToolBar(CrossArrows* cursor,QWidget *parent)
    : QWidget{parent}
{
    auto hBox = new QHBoxLayout();
    hBox->addWidget(new QLabel("Diameter "));
    d->setSuffix(" mm");
    d->setRange(0,250);
    d->setValue(cursor->getDiameter());
    hBox->addWidget(d);
    hBox->addWidget(new QLabel("Color "));
    colorsList->addItems(QStringList{"Red", "Green", "Blue", "Yellow" ,"Gray" ,"White"});
    hBox->addWidget(colorsList);
    setLayout(hBox);

    connect(d,&QDoubleSpinBox::textChanged,[cursor](QString d){
        cursor->setCircleDiameter(int(d.split(" ")[0].toDouble()));
    });
    connect(colorsList,&QComboBox::currentTextChanged,[cursor](QString colorName){
        cursor->setColor(QColor(colorName));
    });
}
