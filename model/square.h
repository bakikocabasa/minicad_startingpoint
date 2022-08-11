#ifndef square_h
#define square_h

#include <string>
#include "shape.h"

namespace tubs::model
{

class Square : public Shape
{
public:
    Square(int x, int y, int len, Observer* observer);
    virtual void draw(ui::Canvas* canvas) const;

private:
    int length = 1;
};

}

#endif
