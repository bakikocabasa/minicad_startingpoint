#include "point.h"

namespace tubs::model
{

Point::Point(double x, double y):
x(x), y(y)
{
}

void Point::translate(double dx, double dy)
{
    x += dx;
    y += dy;
}

}
