#ifndef CURSORTOOLBAR_H
#define CURSORTOOLBAR_H

#include <QWidget>
#include "PCBCursor.h"
#include <QLabel>
#include <QDoubleSpinBox>
#include <QColor>
#include <QBoxLayout>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QWheelEvent>
#include <QKeyEvent>
/*
 * Tool looks like:
    +----------+----------+-------+------+
    | Diameter | __,__ mm | Color | |  | |
    +----------+----------+-------+------+
*/
class CrossArrowToolBar : public QWidget
{
    Q_OBJECT
    QDoubleSpinBox* diameterBox = new QDoubleSpinBox();
    QComboBox * colorsList = new QComboBox();
public:
    explicit CrossArrowToolBar(Cursor* cursor,QWidget *parent = nullptr);
};

#endif // CURSORTOOLBAR_H
