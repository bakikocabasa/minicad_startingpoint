#ifndef circle_h
#define circle_h

#include <string>
#include "shape.h"

namespace tubs::model
{


class Circle : public Shape
{
public:
    Circle(int x, int y, double r, Observer* observer);
    virtual void draw(ui::Canvas* canvas) const;

private:
    double radius = 1.0;
};

}


#endif
