#include "circle.h"

#include "canvas.h"

namespace tubs::model
{

Circle::Circle(int x, int y, double r, Observer* observer) :
Shape(x, y, observer), radius(r)
{}


void Circle::draw(ui::Canvas* canvas) const
{
    int f = 1 - radius;
    int ddf_x = 1;
    int ddf_y = -2 * radius;
    int x = 0;
    int y = radius;
    canvas->drawPixel(center.x, center.y + radius);
    canvas->drawPixel(center.x, center.y - radius);
    canvas->drawPixel(center.x + radius, center.y);
    canvas->drawPixel(center.x - radius, center.y);

    while (x < y) {
        if (f >= 0) {
            y -= 1;
            ddf_y += 2;
            f += ddf_y;
        }
        x += 1;
        ddf_x += 2;
        f += ddf_x;
        canvas->drawPixel(center.x + x, center.y + y);
        canvas->drawPixel(center.x - x, center.y + y);
        canvas->drawPixel(center.x + x, center.y - y);
        canvas->drawPixel(center.x - x, center.y - y);
        canvas->drawPixel(center.x + y, center.y + x);
        canvas->drawPixel(center.x - y, center.y + x);
        canvas->drawPixel(center.x + y, center.y - x);
        canvas->drawPixel(center.x - y, center.y - x);
    }
    canvas->printAtPos(center.x, center.y, std::to_string(id));
    canvas->refresh();
}

}
