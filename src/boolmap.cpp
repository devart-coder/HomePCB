#include "boolmap.h"

boolMap::boolMap(int w, int h, int offset)
    :width(w/offset),height(h/offset),offset(offset)
{
    space = QVector<QVector<bool>>(height);
    for(int i=0; i<height; ++i)
        space[i] = QVector<bool>(width);
}

boolMap::boolMap(const QRect &rect, int offset)
    :boolMap(rect.width(), rect.height(), offset)
{ }

int boolMap::getOffset(){
    return offset;
}

void boolMap::set(int line, int row, bool state)
{
    if(line > width || row > height)
        throw QString("Exception: OutOfBounds");
    space[line][row]=state;
}

bool boolMap::get(int line, int row)
{
    return space.at(line).at(row);
}

QDebug boolMap::toString(QDebug dbg){
    for(int i=0; i<height; ++i){
        dbg << QString::number(i) + "|";
        for(int j=0; j<width; ++j)
            dbg << QString::number (space[i][j]==1?true:false) ;
        dbg << Qt::endl;
    }
    return dbg;
}

