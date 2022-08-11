#ifndef window_h
#define window_h

#include <string>
#include <curses.h>
#include <stdarg.h>

namespace tubs::ui
{

class Window
{
public:
    Window(int height, int width, int startX, int startY);
    virtual ~Window();
    virtual int height();
    virtual int width();

    virtual void refresh();
    virtual void moveCursor(int x, int y);
//    virtual void print(const char * str, ...);
    virtual void println(const char * str, ...);
    template<typename... Args>
    void print(const char * f, Args... args) {
    //      printf(f, args...);
      wprintw(_win, f, args ...);
    }
    virtual void printAtPos(int x, int y, std::string str);
    virtual void clear();
    virtual int getChar();
    virtual std::string getStr();
    virtual void enableScrolling();
    virtual void disableScrolling();
    virtual void enableKeypad();
    virtual void disableKeypad();


protected:
    WINDOW* _win {nullptr};
};

}

#endif
