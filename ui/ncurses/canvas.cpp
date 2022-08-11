#include "canvas.h"

#include <cmath>
#include <sstream>

namespace tubs::ui
{

Canvas::Canvas(int height, int width, int startX, int startY) :
Window(height, width, startX, startY)
{
    clear();
}

void Canvas::moveCursor(int x, int y)
{
    Window::moveCursor(2*x, y);
}

int Canvas::width(){ return (getmaxx(_win)/2-2); }
int Canvas::height(){ return (getmaxy(_win)-2); }

void Canvas::clear()
{
    Window::clear();
    box(_win, ACS_VLINE, ACS_HLINE);
    Window::moveCursor(0, 0);
    print("X");
    std::stringstream output;
    output << "Height:" << this->height() <<" Width:" << this->width();
    Window::moveCursor(1, 1);
    print(output.str().c_str());
}

void Canvas::drawPixel(int x, int y)
{
    moveCursor(x, y);
    print("*");
}

void Canvas::drawLine( int x1, int y1, int x2, int y2)
{
   // Bresenham's line algorithm
   // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
  const bool steep = (std::fabs(y2 - y1) > std::fabs(x2 - x1));
  if(steep)
  {
    std::swap(x1, y1);
    std::swap(x2, y2);
  }

  if(x1 > x2)
  {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }

  const float dx = x2 - x1;
  const float dy = std::fabs(y2 - y1);

  float error = dx / 2.0f;
  const int ystep = (y1 < y2) ? 1 : -1;
  int y = (int)y1;

  const int maxX = (int)x2;

  for(int x=(int)x1; x<=maxX; x++)
  {
    if(steep)
    {
        drawPixel(y, x);
    }
    else
    {
        drawPixel(x, y);
    }

    error -= dy;
    if(error < 0)
    {
        y += ystep;
        error += dx;
    }
  }
}


}
