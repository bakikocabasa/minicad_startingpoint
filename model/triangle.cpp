#include "triangle.h"

#include "canvas.h"
#include <cmath>

namespace tubs::model
{

Triangle::Triangle(int x, int y, int length, Observer* observer):
Shape(x,y, observer), length(length)
{}

void Triangle::scale(double scaling_coeff)
{
    length*=scaling_coeff;
    observer->update();
}

void Triangle::draw(ui::Canvas* canvas) const
    {   const int half_length = int(length/2);
        const int drag_coeff=int((length/2/(2*sqrt(3.0))));


        canvas->drawLine(center.x , center.y -(drag_coeff+1),center.x+half_length ,center.y-(drag_coeff+1));// horizontal line to the right
        canvas->drawLine(center.x+half_length,center.y-(drag_coeff+1) ,center.x,center.y +half_length-(drag_coeff+1)); // angled line on the right corner
        canvas->drawLine(center.x-half_length ,center.y-(drag_coeff+1) ,center.x,center.y +half_length-(drag_coeff+1)); // angled line on the left corner
        canvas->drawLine(center.x,center.y-(drag_coeff+1),center.x-half_length,center.y-(drag_coeff+1)); // horizontal line to the left


        canvas->printAtPos(center.x, center.y, std::to_string(id));
        canvas->refresh();

    }

}
