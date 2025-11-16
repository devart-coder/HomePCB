#ifndef SPOT_H
#define SPOT_H

#include <QObject>

class Spot : public QRectF
{
public:
    explicit Spot(QObject *parent = nullptr);

signals:
};

#endif // SPOT_H
