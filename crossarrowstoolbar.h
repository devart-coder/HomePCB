#ifndef CROSSARROWSTOOLBAR_H
#define CROSSARROWSTOOLBAR_H

#include <QWidget>
#include "crossarrows.h"
#include <QLabel>
#include <QDoubleSpinBox>
#include <QColor>
#include <QBoxLayout>
#include <QDoubleSpinBox>
#include <QComboBox>
class CrossArrowToolBar : public QWidget
{
    Q_OBJECT
    QDoubleSpinBox* d = new QDoubleSpinBox();
    QComboBox * colorsList = new QComboBox();
public:
    explicit CrossArrowToolBar(CrossArrows* cursor,QWidget *parent = nullptr);
};

#endif // CROSSARROWSTOOLBAR_H
