#ifndef HDOUBLE_H
#define HDOUBLE_H

#include "observable.h"

namespace horti {
namespace observable {

class HDouble : public Observable
{
    Q_OBJECT
public:
    explicit HDouble(QObject *parent = 0) :
        Observable(TYPE_DOUBLE, parent),
        value(0.0) {};
    
signals:
    void valueChanged(qreal v);
    
public slots:
    void setValue(qreal v)
    {
        if (value == v) return;
        value = v;
        update();
    };

    void update() { emit valueChanged( value ); };

private:
    qreal value;
    
};

}
}

#endif // HDOUBLE_H
