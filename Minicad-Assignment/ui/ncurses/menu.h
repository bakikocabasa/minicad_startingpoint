#ifndef menu_h
#define menu_h

#include <list>
#include <iostream>
#include <functional>
#include <ncurses.h>

#include "window.h"

namespace tubs::ui {

struct MenuEntry
{
    MenuEntry(std::string title, char key, std::function<void(void)> cb)
    : title(title), key(key), callback(cb) { }

    const std::string title;
    const char key;
    const std::function<void(void)> callback;
};


class Menu
{
public:
    Menu(Window* win);
    void show();
    void addEntry(MenuEntry entry);

private:
    void _printMenu();

private:
    Window* _win {nullptr};
    std::list<MenuEntry> _entries;
};

}




#endif
