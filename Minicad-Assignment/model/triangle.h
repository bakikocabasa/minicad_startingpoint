#ifndef triangle_h
#define triangle_h

#include <string>
#include "shape.h"

namespace tubs::model
{

class Triangle : public Shape
{
public:
    Triangle(int x, int y, int len, Observer* observer);
    virtual void draw(ui::Canvas* canvas) const;

private:
    int length = 1;
};

}

#endif
