#ifndef POINTINSPECTOR_H
#define POINTINSPECTOR_H

#include <QWidget>
#include <QDoubleSpinBox>

namespace horti {
namespace builder {

class PointInspector : public QWidget
{
    Q_OBJECT
public:
    explicit PointInspector(QWidget *parent = 0);
    
signals:
    void valueChanged(const QPointF& p);
    
public slots:
    void setValue(const QPointF& p);
    void spinValueChanged();

private:
    QDoubleSpinBox* spinX;
    QDoubleSpinBox* spinY;
};

}
}

#endif // POINTINSPECTOR_H
