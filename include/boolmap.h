#ifndef BOOLMAP_H
#define BOOLMAP_H

#include <QObject>
#include <QRectF>
#include <QDebug>
class boolMap : public QObject
{
    //QVector<QMap<>>
    Q_OBJECT
    int height;
    int width;
    //QMap<QPoint,bool> //Hash or Tree
    QVector<QVector<bool>> space;
    int offset;
public:
    boolMap() = delete;
    boolMap(const boolMap&) = delete;
    boolMap(int w, int h, int offset = 100);
    boolMap(const QRect& rect, int offset = 100);

public:
    int getOffset();
    void set(int line, int row, bool state);
    bool get(int line, int row);
    QDebug toString(QDebug dbg);
};

#endif // BOOLMAP_H
