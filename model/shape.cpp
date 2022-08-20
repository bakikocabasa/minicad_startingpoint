#include "shape.h"

#include "logger.h"

namespace tubs::model
{

int Shape::counter = 0;

Shape::Shape(int x, int y, Observer* observer) : center(x,y), observer(observer)
{
    id = counter++;
}

void Shape::translate(float dx, float dy)
{
    center.translate(dx, dy);

    observer->update();
}

void Shape::scale(double scaling_coeff)
{
    scale(scaling_coeff);

    observer->update();
}


}
