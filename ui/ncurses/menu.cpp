#include "menu.h"

namespace tubs::ui
{

Menu::Menu(Window* win)
{
    _win = win;
    _win->enableScrolling();
    _win->enableKeypad();
}

void Menu::show()
{
    noecho();
    _printMenu();

    int c;
    while ((c = _win->getChar()) != 27) {

        for (auto e : _entries) {
            if (c == e.key) {
                e.callback();
            }
        }

        switch (c) {
//                case KEY_DOWN:
//                    _win->println("KEY_DOWN : %d", c);
//    //                wscrl(console, -1);
//                    break;
//                case KEY_UP:
//                    _win->println("KEY_UP   : %d", c);
//    //                wscrl(console, 1);
//                    break;
//                case KEY_LEFT:
//                    _win->println("KEY_LEFT : %d", c);
//                    break;
//                case KEY_RIGHT:
//                    _win->println("KEY_RIGHT: %d", c);
//                    break;
            case 'i':
                _win->clear();
                _win->moveCursor(0, _win->height()-1);
                _win->println("Please enter a name:");
                echo();
                _win->refresh();
                _win->getStr();
                break;
//                default:
//                    _win->print("Key code %d\n", c);
//                    _win->getChar();
        }
        noecho();
        _printMenu();
    }
}

void Menu::addEntry(MenuEntry entry)
{
    _entries.push_back(entry);
}

void Menu::_printMenu()
{
    _win->clear();
    _win->moveCursor(0, _win->height()-1);
    _win->print("Press ...\n");
    for (auto e : _entries) {
        _win->print("%c) to %s\n",e.key, e.title.c_str());
    }
    _win->print("\n");
    _win->print("ESC to go back ...\n");
    _win->refresh();
}

}
