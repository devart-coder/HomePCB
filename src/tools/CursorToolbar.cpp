#include "CursorToolbar.h"
#include <QDebug>
CrossArrowToolBar::CrossArrowToolBar(Cursor *cursor, QWidget *parent)
    : QWidget{parent}
{
    auto hBox = new QHBoxLayout();
    //AddDiameterLabel
    hBox->addWidget(new QLabel("Diameter "));

    //AddDiameterBox
    diameterBox->setRange(0,250);
    diameterBox->setValue(cursor->spot()->getDiameter());
    diameterBox->setSuffix(" mm");
    hBox->addWidget(diameterBox);

    //AddColorLabel
    hBox->addWidget(new QLabel("Color "));

    //AddColorList
    colorsList->addItems(QStringList{"Red", "Green", "Blue", "Yellow" ,"Gray" ,"White"});
    hBox->addWidget(colorsList);

    setLayout(hBox);

    connect(diameterBox,&QDoubleSpinBox::valueChanged,[cursor](double d){
        //bool ok;
        cursor->spot()->setDiameter(d);
        cursor->update();
    });
    connect(colorsList,&QComboBox::currentTextChanged,[cursor](QString colorName){
        cursor->spot()->setColor(QColor(colorName));
        cursor->update();
    });
}
