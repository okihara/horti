#include <QHBoxLayout>
#include "pointinspector.h"

namespace horti {
namespace builder {

PointInspector::PointInspector(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* l = new QHBoxLayout();

    spinX = new QDoubleSpinBox();
    spinX->setRange( -1000000, 1000000 );
    l->addWidget( spinX );

    spinY = new QDoubleSpinBox();
    spinY->setRange( -1000000, 1000000 );
    l->addWidget( spinY );

    this->setLayout( l );

    connect(spinX, SIGNAL(editingFinished()), this, SLOT(spinValueChanged()));
    connect(spinY, SIGNAL(editingFinished()), this, SLOT(spinValueChanged()));
}

void PointInspector::setValue(const QPointF &p)
{
    spinX->setValue( p.x() );
    spinY->setValue( p.y() );
}

void PointInspector::spinValueChanged()
{
    emit valueChanged( QPointF( spinX->value(), spinY->value() ) );
}

}
}
