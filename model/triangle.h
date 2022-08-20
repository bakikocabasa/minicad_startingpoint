#ifndef triangle_h
#define triangle_h

#include <string>
#include "shape.h"

namespace tubs::model
{

class Triangle : public Shape
{
public:
    Triangle(int x, int y, int length, Observer* observer);
    virtual void draw(ui::Canvas* canvas) const;
    virtual void scale(double scaling_coeff);
private:
    int length = 1;
 
};

}

#endif
