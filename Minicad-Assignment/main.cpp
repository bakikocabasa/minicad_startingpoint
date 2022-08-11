#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <signal.h>
#include <curses.h>
#include <termios.h>

#include "screen.h"
#include "window.h"
#include "canvas.h"
#include "console.h"
#include "menu.h"


#include "circle.h"
#include "square.h"
#include "triangle.h"
// we should include the shape file that we prefer.
#include "command_stack.h"
#include "logger.h"

#include "create_circle_command.h"
#include "create_square_command.h"
#include "create_triangle_command.h"
#include "translate_shape_command.h"
#include "remove_shape_command.h"
#include "scale_shape_command.h"
// TODO: add includes from new header files here
// ...

using namespace tubs;
using namespace tubs::model;

void resizeHandler(int);


class ShapeListObserver : public Observer
{
public:
    ShapeListObserver(ui::Canvas& canvas, std::vector<Shape*>& shapes) : canvas(canvas), shapes(shapes) {}
    void update() {
        Logger::getInstance().print("Observer::update");

        canvas.clear();
        for(auto& shape : shapes)
            shape->draw(&canvas);
         canvas.refresh();
    }

private:
    ui::Canvas& canvas;
    std::vector<Shape*>& shapes;
};


ui::MenuEntry createCreateMenuEntry(ui::CommandStack* commandStack, std::vector<Shape*>* shapes, ui::Window* console, Observer* observer)
{
    ui::Menu createMenu(console);

    createMenu.addEntry(ui::MenuEntry("Circle", 'c', [=]()->void {
        echo();
        console->clear();
        console->print("Create circle ...\n");
        console->print("Center x:");
        int x = std::stoi(console->getStr().c_str()) ;
        console->print("Center y:");
        int y = std::stoi(console->getStr().c_str()) ;
        console->print("radius:");
        int radius = std::stoi(console->getStr().c_str()) ;

        ui::CreateCircleCommand* c = new ui::CreateCircleCommand(*shapes, x, y, radius, observer);
        commandStack->execute(c);
    }));

     // square
    createMenu.addEntry(ui::MenuEntry("Square", 's', [=]()->void {
        echo();
        console->clear();
        console->print("Create square ...\n");
        console->print("Center x:");
        int x = std::stoi(console->getStr().c_str()) ;
        console->print("Center y:");
        int y = std::stoi(console->getStr().c_str()) ;
        console->print("length:");
        int length = std::stoi(console->getStr().c_str()) ;

        ui::CreateSquareCommand* s = new ui::CreateSquareCommand(*shapes, x, y, length, observer);
        commandStack->execute(s);
    }));
        //*triangle
    createMenu.addEntry(ui::MenuEntry("Triangle", 't', [=]()->void {
        echo();
        console->clear();
        console->print("Create triangle ...\n");
        console->print("Center x:");
        int x = std::stoi(console->getStr().c_str()) ;
        console->print("Center y:");
        int y = std::stoi(console->getStr().c_str()) ;
        console->print("length:");
        int length = std::stoi(console->getStr().c_str()) ;

        ui::CreateTriangleCommand* t = new ui::CreateTriangleCommand(*shapes, x, y, length, observer);
        commandStack->execute(t);
    }));
    //*

    auto showCreateMenuCmd = [=]() mutable -> void {
        createMenu.show();
    };

    return ui::MenuEntry("Create", 'c', showCreateMenuCmd);
}


/*
/ Application
*/
int main() {
    // safe terminal settings
    // https://arstechnica.com/civis/viewtopic.php?f=20&t=70699
    struct termios old_settings;
    tcgetattr( 0, &old_settings );

    signal(SIGWINCH, resizeHandler);

    ui::Screen screen;
    screen.clear();

    int consoleWidth = 30;

    // the cavas window is used to draw the shapes
    ui::Canvas canvas(screen.height(), screen.width() - consoleWidth * 2, 0, 0);
    canvas.refresh();

    // the console is used to print the menu entries
    ui::Console console(screen.height(), consoleWidth, screen.width()-consoleWidth * 2, 0);

    // the console is used to print log messages
    ui::Console log_console(screen.height(), consoleWidth, screen.width()-consoleWidth, 0);

    // logging can be done by accessing the Singelton `Logger`.
    // In the first call log_console needs to be passed...
    Logger::getInstance(&log_console).print("Start Logging...");
    // Afterwards we can log text messages like this:
    Logger::getInstance().print("mini CAD Application - Answer to all questions: " + std::to_string(42));
    // logger only works with the strings, so we should not pass any integer inside of it.
    // example : Logger :: getInstance().print(std :: to_string(radius) +" -Hello CSE");

    // The ´CommandStack´ is responsible for implementing the undo/redo functionality
    ui::CommandStack commandStack;

    // This vector of shapes stores all shapes, which are visible in our canvas
    std::vector<Shape*> shapes;

    // The ´ShapeListObserver´ implements the ´Observer´ interface.
    // His responsiblity is to redraw all shapes when something changes in our canvas
    ShapeListObserver observer(canvas, shapes);


    // MENU
    ui::Menu mainMenu(&console);

    // MENU: creating objects
    mainMenu.addEntry(createCreateMenuEntry(&commandStack, &shapes, &console, &observer));

    // MENU: translation
    mainMenu.addEntry(ui::MenuEntry("Move", 'm', [&]()->void{
        echo();
        console.clear();
        console.print("Choose shape: ");
        const std::size_t shapeNumber = std::stoi(console.getStr().c_str());
        if(shapeNumber >= shapes.size())
            return;

        console.print("Delta x:");
        int dx = std::stoi(console.getStr().c_str());
        console.print("Delta y:");
        int dy = std::stoi(console.getStr().c_str());
        ui::TranslateShapeCommand* c = new ui::TranslateShapeCommand(shapes[shapeNumber], dx, dy);
        commandStack.execute(c);
    }));

    // TODO: add menu entry for scaling here. Use the translate menu item above as a guide.
    // ...

    // MENU: remove
    mainMenu.addEntry(ui::MenuEntry("Delete", 'd', [&]()->void{
        echo();
        console.clear();
        console.print("Choose shape: ");
        const std::size_t shapeNumber = std::stoi(console.getStr().c_str());
        if(shapeNumber >= shapes.size())
            return;

        ui::RemoveShapeCommand* c = new ui::RemoveShapeCommand(shapes, shapeNumber, &observer);
        commandStack.execute(c);
    }));


    // MENU: undo
    mainMenu.addEntry(ui::MenuEntry("Undo", 'u', [&]()->void {
        commandStack.undo();
    }));

    // MENU: redo
    mainMenu.addEntry(ui::MenuEntry("Redo", 'r', [&]()->void {
        commandStack.redo();
    }));


    mainMenu.show();

    // restore terminal settings (e.g. to enable carriage return)
    tcsetattr( 0, TCSANOW, &old_settings );
    return 0;
}

void resizeHandler(int sig)
{
    // clear();
    // refresh ();
    // int screenHeight = getmaxy(stdscr);
    // int screenWidth = getmaxx(stdscr);
    // std::ostringstream output;
    // output << "Screen height:" << screenHeight <<" width:" << screenWidth/2;
    // mvwaddstr(stdscr, screenHeight-1, 0, output.str().c_str());
    // refresh();
    // getmaxyx(stdscr, nh, nw);  /* get the new screen size */
}
