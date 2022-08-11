#include "square.h"

#include "canvas.h"

namespace tubs::model
{

Square::Square(int x, int y, int len, Observer* observer):
Shape(x,y, observer), length(len)
{}


void Square::draw(ui::Canvas* canvas) const
{
    const int half_length = int(length/2);

    for (int y=0;  y<length; y++) {
        canvas->drawPixel(center.x - half_length, center.y - half_length + y);
        canvas->drawPixel(center.x + half_length, center.y - half_length + y);
    }

    for (int x=0;  x<length + (length+1)%2; x++) {
        canvas->drawPixel(center.x - half_length + x, center.y - half_length);
        canvas->drawPixel(center.x - half_length + x, center.y + half_length);
    }
    canvas->printAtPos(center.x, center.y, std::to_string(id));
    canvas->refresh();
}

}
