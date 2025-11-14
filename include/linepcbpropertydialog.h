#ifndef LINEPCBPROPERTYDIALOG_H
#define LINEPCBPROPERTYDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QVector>
#include <QLayout>
#include <QComboBox>
#include <QPushButton>
#include <QPointF>
#include <QObject>
#include <QDebug>

/* +----------------------------------------------------+
 * |					  NAME "____"					|
 * +----------------------------------------------------+
 * |	StartPoint | X = __.__mm  	 |  Y = __.__mm	   	|
 * |	EndPoint   | X = __.__mm  	 |	Y = __.__mm	 	|
 * +---------------------------------------------------	|
 * | Widght    = __.__mm  	 	Color  :|_____________|	|
 * +----------------------------------------------------+
 */


class LinePCBPropertyDialog : public QDialog
{
    Q_OBJECT
    QVector<QDoubleSpinBox*> linePropertiesVector = QVector<QDoubleSpinBox*> (6);
    QComboBox* colorsList = new QComboBox();
    void connectorsInitialize();
public:
    enum LinePositionEnum{
        STARTXPOSITION,
        STARTYPOSITION,
        ENDXPOSITION,
        ENDYPOSITION,
        WIDTHSPIN,
    };
    LinePCBPropertyDialog(QWidget *parent = nullptr, const Qt::WindowFlags &f = Qt::WindowFlags());
    QVector<QDoubleSpinBox *> getLinePropertiesVector();
    void setStartPoint(const QPointF& startPoint);
    void setEndPoint(const QPointF& endPoint);
    void setWidthLine(int width);
private slots:
    void getStartXPosition(double d);
    void getStartYPosition(double d);
    void getEndXPosition(double d);
    void getEndYPosition(double d);
    void getWidth(double d);
signals:
    void startXPositionChanged(const double value);
    void startYPositionChanged(const double value);
    void endXPositionChanged(const double value);
    void endYPositionChanged(const double value);
    void widthChanged(const double value);
    void colorChange(const QColor color);
};

#endif // LINEPCBPROPERTYDIALOG_H
