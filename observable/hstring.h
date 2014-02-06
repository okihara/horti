#ifndef HSTRING_H
#define HSTRING_H

#include <QString>
#include "observable.h"

namespace horti {
namespace observable {

class HString : public Observable
{
    Q_OBJECT
public:
    explicit HString(QObject *parent = 0) :
        Observable(TYPE_STRING, parent) {};

signals:
    void valueChanged(const QString& v);
    
public slots:
    void setValue(const QString& v)
    {
        if (value == v) return;
        value = v;
        update();
    };

    void update() { emit valueChanged( value ); };

private:
    QString value;
};

}
}

#endif // HSTRING_H
