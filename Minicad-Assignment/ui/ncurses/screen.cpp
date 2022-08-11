#include "screen.h"

namespace tubs::ui
{

Screen::Screen()
{
    initscr();
    cbreak();
}

Screen::~Screen()
{
    endwin();
}

void Screen::clear()
{
    wclear(stdscr);
    refresh();
}

int Screen::height()
{
    return getmaxy(stdscr);
}

int Screen::width()
{
     return getmaxx(stdscr); }
}
