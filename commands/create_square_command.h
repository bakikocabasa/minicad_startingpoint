#ifndef __CREATE_SQUARE_COMMAND_H__
#define __CREATE_SQUARE_COMMAND_H__

#include <vector>

#include "window.h"

#include "command.h"
#include "shape.h"

namespace tubs::ui
{

class CreateSquareCommand : public Command
{
public:
    CreateSquareCommand(std::vector<model::Shape*>& shapes, int x, int y, int length, model::Observer* observer); // update the inputs

    virtual void execute();

    virtual void undo();

    virtual void redo();

private:
    std::vector<model::Shape*>& shapes;

    int x;
    int y;
    int length; // update the inputs

    model::Observer* observer;

    model::Shape* shape = nullptr;
};

}

#endif
