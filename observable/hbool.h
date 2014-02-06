#ifndef HBOOL_H
#define HBOOL_H

#include "observable.h"

namespace horti {
namespace observable {

class HBool : public Observable
{
    Q_OBJECT
public:
    explicit HBool(QObject *parent = 0) :
        Observable(TYPE_BOOL, parent),
        value(false) {};

signals:
    void valueChanged(bool v);

public slots:
    void setValue(bool v)
    {
        if (value == v) return;
        value = v;
        update();
    };

    void update() { emit valueChanged( value ); };

private:
    bool value;
    
};

}
}

#endif // HBOOL_H
