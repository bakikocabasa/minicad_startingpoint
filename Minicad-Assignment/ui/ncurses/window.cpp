#include "window.h"

namespace tubs::ui
{

Window::Window(int height, int width, int startX, int startY)
{
    _win = newwin(height, width, startY, startX);
    disableScrolling();
}

Window::~Window()
{
    delwin(_win);
}

int Window::height(){ return getmaxy(_win); }
int Window::width(){ return getmaxx(_win); }

void Window::refresh()
{
    if(is_wintouched(_win))
    // dann zeichne neu
        wrefresh(_win);
    else {
        // tu so, als ob das Fenster verändert wurde
        touchwin(_win);
        // ... und zeichne dann neu
        wrefresh(_win);
    }
}

void Window::moveCursor(int x, int y)
{
    wmove(_win, y, x);
}


// https://stackoverflow.com/questions/3530771/passing-variable-arguments-to-another-function-that-accepts-a-variable-argument
//void Window::print(const char * str, ...)
//{
//    va_list args;
//    va_start(args, str);
//    wprintw(_win, str, args);
//    va_end(args);
//}

void Window::println(const char * str, ...)
{
    va_list args;
    va_start(args, str);
    print(str, args, "\n");
    va_end(args);
}

void Window::clear() { wclear(_win); }

int Window::getChar() { return wgetch(_win); }

std::string Window::getStr()
{
    char* strBuffer = new char[160];
    wgetnstr(_win, strBuffer, 160);
    std::string result = std::string(strBuffer);
    delete[] strBuffer;
    return result;
}

void Window::printAtPos(int x, int y, std::string str)
{
    moveCursor(x,y);
    print(str.c_str());
}

void Window::enableScrolling() { scrollok (_win, TRUE); }
void Window::disableScrolling() { scrollok (_win, FALSE); }

void Window::enableKeypad() { keypad(_win, TRUE); }
void Window::disableKeypad() { keypad(_win, FALSE); }

}
