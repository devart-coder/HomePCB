#ifndef BOOLMAP_H
#define BOOLMAP_H

#include<QObject>
#include<QRectF>
#include <QDebug>
class boolMap : public QObject
{
    //QVector<QMap<>>
    Q_OBJECT
    int height;
    int width;
    bool** space;
    int offset;
public:
    boolMap() = delete;
    boolMap(int w, int h, int offset = 100);
    boolMap(const QRect& rect, int offset = 100);

public:
    int getOffset();
    const bool& at(int i);
    QDebug toString(QDebug dbg);
};

#endif // BOOLMAP_H
