#ifndef screen_h
#define screen_h

#include <curses.h>

namespace tubs::ui
{

class Screen
{
public:
    Screen();
    ~Screen();
    void clear();
    int height();
    int width();
};

}

#endif
