#ifndef console_h
#define console_h

#include "window.h"

namespace tubs::ui
{

class Console : public Window
{
public:
    Console(int height, int width, int startX, int startY);
    virtual void clear();
};

}

#endif
