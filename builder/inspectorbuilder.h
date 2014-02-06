#ifndef INSPECTORBUILDER_H
#define INSPECTORBUILDER_H

#include <QVBoxLayout>
#include "edititem.h"

namespace horti {
namespace builder {

class InspectorBuilder
{
public:
    InspectorBuilder();
    static QWidget* buildGUI(EditItem*);

private:
    static QWidget* _buildGUI(QObject* target, const int vartype);
};

}
}

#endif // INSPECTORBUILDER_H
