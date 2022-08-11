#ifndef __CREATE_CIRCLE_COMMAND_H__
#define __CREATE_CIRCLE_COMMAND_H__

#include <vector>

#include "window.h"

#include "command.h"
#include "shape.h"

namespace tubs::ui
{

class CreateCircleCommand : public Command
{
public:
    CreateCircleCommand(std::vector<model::Shape*>& shapes, int x, int y, int radius, model::Observer* observer);

    virtual void execute();

    virtual void undo();

    virtual void redo();

private:
    std::vector<model::Shape*>& shapes;

    int x;
    int y;
    int radius;

    model::Observer* observer;

    model::Shape* shape = nullptr;
};

}

#endif
