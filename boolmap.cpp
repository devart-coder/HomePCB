#include "boolmap.h"

boolMap::boolMap(int w, int h, int offset)
    :width(w/offset),height(h/offset)
{
    space = new bool* [height];
    for(int i=0; i<height; ++i)
        space[i]=new bool[width]{false};
    this->offset=offset;
}

boolMap::boolMap(const QRect &rect, int offset)
    :boolMap(rect.width(), rect.height(), offset)
{ }

int boolMap::getOffset(){
    return offset;
}

const bool &boolMap::at(int i){
    return space[i];
}

QDebug boolMap::toString(QDebug dbg){
    for(int i=0; i<height; ++i){
        dbg << QString::number(i) + "|";
        for(int j=0; j<width; ++j)
            dbg << QString::number (space[i][j]==1?true:false) ;
        dbg << endl;
    }
    return dbg;
}

