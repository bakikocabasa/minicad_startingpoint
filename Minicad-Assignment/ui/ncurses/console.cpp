#include "console.h"

namespace tubs::ui
{

Console::Console(int height, int width, int startX, int startY) :
Window(height, width, startX, startY)
{
}

void Console::clear()
{
    Window::clear();
    moveCursor(0, height()-1);
}

}
