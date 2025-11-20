#ifndef GCODEWIDGET_H
#define GCODEWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QCompleter>
#include <QTreeWidget>
#include <QGraphicsItem>
#include <QMap>
#include <QVector>
#include <QLineF>
#include "PCBLine.h"

class GCodeWidget : public QWidget
{
    Q_OBJECT
    QPushButton* okButton = new QPushButton("OK");
    QLineEdit* comLine = new QLineEdit();
    QTreeWidget* treeWidget = new QTreeWidget();
    QVector<QLineF> lines;
    QMap<QString,QString> colorNames {
        {"#ff0000", "RED"},
        {"#008000", "GREEN"},
        {"#0000ff", "BLUE"},
        {"#ffffff", "WHITE"},
        {"#ffff00", "YELLOW"},
        {"#808080", "GRAY"}
    };
public:
    explicit GCodeWidget(QWidget *parent = nullptr);
signals:

private:
    void comLineInitialize();
    QTreeWidget* modelInitialize();
public slots:
    void addShape(QGraphicsItem* item);
    void deleteShape(QGraphicsItem* item);
};

#endif // GCODEWIDGET_H
