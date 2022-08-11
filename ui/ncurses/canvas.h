#ifndef canvas_h
#define canvas_h

#include "window.h"

namespace tubs::ui
{

class Canvas : public Window
{
public:
    Canvas(int height, int width, int startX, int startY);
    virtual int width();
    virtual int height();
    virtual void moveCursor(int x, int y);
    virtual void clear();
    virtual void drawPixel(int x, int y);
    virtual void drawLine(int x1, int y1, int x2, int y2);
};

}

#endif
