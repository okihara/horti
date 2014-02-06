#ifndef HENUM_H
#define HENUM_H

#include <QStringList>
#include "observable.h"

namespace horti {
namespace observable {

class HEnum : public Observable
{
    Q_OBJECT
public:
    explicit HEnum(QObject *parent = 0) :
        Observable(TYPE_ENUM, parent),
        value(0) {};

    QStringList enumList() {
        QStringList enumList;
        enumList << "one" << "two" << "three";
        return enumList;
    };

signals:
    void valueChanged(int v);

public slots:
    void setValue(int v)
    {
        if (value == v) return;
        value = v;
        update();
    }

    void update() { emit valueChanged( value ); };

private:
    int value;
};

}
}

#endif // HENUM_H
