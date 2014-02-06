#ifndef HPOINT_H
#define HPOINT_H

#include <QPointF>
#include "observable.h"

namespace horti {
namespace observable {

class HPoint : public Observable
{
    Q_OBJECT
public:
    explicit HPoint(QObject *parent = 0) :
        Observable(TYPE_POINT, parent),
        value(0, 0) {};

signals:
    void valueChanged(QPointF v);
    
public slots:
    void setValue(QPointF v)
    {
        if (value == v) return;
        value = v;
        update();
    }

    void update() { emit valueChanged( value ); };

private:
    QPointF value;
};

}
}

#endif // HPOINT_H
