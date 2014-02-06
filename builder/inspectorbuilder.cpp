#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QComboBox>
#include "../observable/hdouble.h"
#include "../observable/hpoint.h"
#include "../observable/hbool.h"
#include "../observable/henum.h"
#include "inspectorbuilder.h"
#include "pointinspector.h"

namespace horti {
namespace builder {

InspectorBuilder::InspectorBuilder()
{
}

QWidget* InspectorBuilder::buildGUI(EditItem* target)
{
    QWidget* panel = new QWidget();

    QVBoxLayout* l = new QVBoxLayout();
    panel->setLayout( l );

    EditItem::PropsIter i( target->props );
    while ( i.hasNext() ) {

        i.next();

        QWidget* p = new QWidget();

        QHBoxLayout* hbox = new QHBoxLayout();

        QObject* t = i.value();
        QLabel* label = new QLabel();
        label->setText( i.key() );
        hbox->addWidget( label );

        QWidget* widget = _buildGUI( t, i.value()->type() );
        hbox->addWidget( widget );

        p->setLayout( hbox );

        l->addWidget( p );
    }

    l->addStretch();

    return panel;
}

QWidget* InspectorBuilder::_buildGUI(QObject* target, const int vartype)
{
    switch (vartype) {

    // Factory
    case TYPE_DOUBLE:
    {
        QDoubleSpinBox* inspector = new QDoubleSpinBox();
        inspector->setRange(-10000000, 10000000);
        QObject::connect( target,    SIGNAL(valueChanged(qreal)), inspector, SLOT(setValue(qreal)) );
        QObject::connect( inspector, SIGNAL(valueChanged(qreal)), target,    SLOT(setValue(qreal)) );
        return inspector;
    }
        break;

    case TYPE_BOOL:
    {
        QWidget* inspector = new QCheckBox;
        QObject::connect( target,    SIGNAL(valueChanged(bool)), inspector, SLOT(setChecked(bool)) );
        QObject::connect( inspector, SIGNAL(toggled(bool)),      target,    SLOT(setValue(bool)) );
        return inspector;
    }
        break;

    case TYPE_STRING:
    {
        QWidget* inspector = new QLineEdit;
        QObject::connect( target,    SIGNAL(valueChanged(const QString &)), inspector, SLOT(setText(const QString&)) );
        QObject::connect( inspector, SIGNAL(textEdited(const QString &)),   target,    SLOT(setValue(const QString&)) );
        return inspector;
    }
        break;

    case TYPE_POINT:
    {
        QWidget* inspector = new PointInspector();
        QObject::connect( target,    SIGNAL(valueChanged(QPointF)), inspector, SLOT(setValue(const QPointF&)) );
        QObject::connect( inspector, SIGNAL(valueChanged(QPointF)), target,    SLOT(setValue(QPointF)) );
        return inspector;
    }
        break;

    case TYPE_ENUM:
    {
        QComboBox* inspector = new QComboBox();
        inspector->addItems( dynamic_cast<HEnum*>( target )->enumList() );
        QObject::connect( target,    SIGNAL(valueChanged(int)),        inspector, SLOT(setCurrentIndex(int)) );
        QObject::connect( inspector, SIGNAL(currentIndexChanged(int)), target,    SLOT(setValue(int)) );
        return inspector;
    }
        break;

    default:
        return NULL;
        break;
    }
}

}
}
