#include "linepcbpropertydialog.h"
#include <QDebug>
#include <QColorDialog>
#include <QAction>
QVector<QDoubleSpinBox *> LinePCBPropertyDialog::getLinePropertiesVector()
{
    return linePropertiesVector;
}

void LinePCBPropertyDialog::setStartPoint(const QPointF &startPoint)
{
    linePropertiesVector[STARTXPOSITION]->setValue(startPoint.x());
    linePropertiesVector[STARTYPOSITION]->setValue(startPoint.y());
}
void LinePCBPropertyDialog::setEndPoint(const QPointF &endPoint)
{
    linePropertiesVector[ENDXPOSITION]->setValue(endPoint.x());
    linePropertiesVector[ENDYPOSITION]->setValue(endPoint.y());
}
void LinePCBPropertyDialog::setWidthLine(int width)
{
    linePropertiesVector[WIDTHSPIN]->setValue(width);
}
void LinePCBPropertyDialog::getStartXPosition(double d){
    emit startXPositionChanged(d);
}
void LinePCBPropertyDialog::getStartYPosition(double d){
    emit startYPositionChanged(d);
}
void LinePCBPropertyDialog::getEndXPosition(double d){
    emit endXPositionChanged(d);
}
void LinePCBPropertyDialog::getEndYPosition(double d){
    emit endYPositionChanged(d);
}
void LinePCBPropertyDialog::getWidth(double d){
    emit widthChanged(d);
}
void LinePCBPropertyDialog::connectorsInitialize()
{
    for(int i=0 ;i != linePropertiesVector.size(); ++i)
        switch(i){
            case STARTXPOSITION:
            connect(linePropertiesVector[i],SIGNAL(valueChanged(double)),SLOT(getStartXPosition(double)));
            break;
            case STARTYPOSITION:
            connect(linePropertiesVector[i],SIGNAL(valueChanged(double)),SLOT(getStartYPosition(double)));
            break;
            case ENDXPOSITION:
            connect(linePropertiesVector[i],SIGNAL(valueChanged(double)),SLOT(getEndXPosition(double)));
            break;
            case ENDYPOSITION:
            connect(linePropertiesVector[i],SIGNAL(valueChanged(double)),SLOT(getEndYPosition(double)));
            break;
            case WIDTHSPIN:
            connect(linePropertiesVector[i],SIGNAL(valueChanged(double)),SLOT(getWidth(double)));
            break;
        }
        connect(colorsList, &QComboBox::textActivated,[&](const QString& str){
            QColor colorName = QColor(str);
            if(colorName == "Other"){
                colorName = QColorDialog::getColor();
            }
            emit colorChange(colorName);
        });
}
LinePCBPropertyDialog::LinePCBPropertyDialog(QWidget *parent, const Qt::WindowFlags &f)
    : QDialog(parent, f){

    colorsList->addItems(QStringList({"Red","Green","Blue","White","Other"}));
    for(auto i : {0,1,2,3,4,5}){
        auto pos = new QDoubleSpinBox();
        pos->setSuffix(" mm");
        linePropertiesVector[i]=pos;
    }
    auto vBox = new QVBoxLayout();
    auto gBox = new QGridLayout();
    //StartPointInitialization
    gBox ->addWidget( new QLabel("StartPoint "),0,0 );
    gBox ->addWidget( new QLabel("X = "),0,1 );
    gBox ->addWidget( linePropertiesVector[STARTXPOSITION],0,2 );
    gBox ->addWidget( new QLabel("Y = "),0,3,Qt::AlignRight);
    gBox ->addWidget( linePropertiesVector[STARTYPOSITION],0,4 ) ;

    //EndPointInitialization
    gBox ->addWidget( new QLabel("EndPoint "),1,0 );
    gBox ->addWidget( new QLabel("X = "),1,1 );
    gBox ->addWidget( linePropertiesVector[ENDXPOSITION],1,2 );
    gBox ->addWidget( new QLabel("Y = "),1,3,Qt::AlignRight );
    gBox ->addWidget( linePropertiesVector[ENDYPOSITION],1,4 ) ;

    //WidthInitialization
    gBox->addWidget(new QLabel("Diameter"),2,0,Qt::AlignLeft);
    gBox->addWidget(new QLabel("= "),2,1,Qt::AlignRight);
    gBox->addWidget( linePropertiesVector[WIDTHSPIN],2,2,Qt::AlignLeft);

    //ColorInitialization
    gBox->addWidget(new QLabel("Color = "),2,3,Qt::AlignLeft);
    gBox->addWidget(colorsList,2,4,Qt::AlignLeft);

    vBox->addLayout(gBox);
    setLayout(vBox);
    connectorsInitialize();
}
/* +----------------------------------------------------+
 * |					  NAME "____"					|
 * +----------------------------------------------------+
 * |	StartPoint | X = __.__mm  	 |  Y = __.__mm	   	|
 * |	EndPoint   | X = __.__mm  	 |	Y = __.__mm	 	|
 * +---------------------------------------------------	|
 * | Widght    = __.__mm  	 	Color  :|_____________|	|
 * +----------------------------------------------------+
 */
