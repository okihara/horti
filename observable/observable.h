#ifndef OBSERVABLEOBJECT_H
#define OBSERVABLEOBJECT_H

#include <QObject>
#include "htypes.h"

namespace horti {
namespace observable {

class Observable : public QObject
{
    Q_OBJECT
public:
    explicit Observable(int type, QObject *parent = 0) :
        QObject( parent ),
        _type( type ) {};

    int type() const { return _type; };

public slots:
    virtual void update() = 0;

private:
    int _type;

};

}
}

#endif // OBSERVABLEOBJECT_H
