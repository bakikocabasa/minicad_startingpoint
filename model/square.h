#ifndef square_h
#define square_h

#include <string>
#include "shape.h"
namespace tubs::model
{

class Square : public Shape
{
public:
    Square(int x, int y, int length, Observer* observer);
    virtual void draw(ui::Canvas* canvas) const;
    virtual void scale(double scaling_coeff);
private:
    int length = 1;
};

}

#endif
