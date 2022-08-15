#include "triangle.h"

#include "canvas.h"
#include <cmath>

namespace tubs::model
{

Triangle::Triangle(int x, int y, int len, Observer* observer):
Shape(x,y, observer), length(len)
{}


void Triangle::draw(ui::Canvas* canvas) const

    {
        const int drag_coeff=int((length/2/(2*sqrt(3.0))));


        canvas->drawLine(center.x , center.y -(drag_coeff+1),center.x+length/2 ,center.y-(drag_coeff+1));// horizontal line to the right
        canvas->drawLine(center.x+length/2 ,center.y-(drag_coeff+1) ,center.x,center.y +length/2-(drag_coeff+1)); // angled line on the right corner
        canvas->drawLine(center.x-length/2 ,center.y-(drag_coeff+1) ,center.x,center.y +length/2-(drag_coeff+1)); // angled line on the left corner
        canvas->drawLine(center.x,center.y-(drag_coeff+1),center.x-length/2,center.y-(drag_coeff+1)); // horizontal line to the left


        canvas->printAtPos(center.x, center.y, std::to_string(id));
        canvas->refresh();

    }

}
