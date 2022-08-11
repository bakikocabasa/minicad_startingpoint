
#ifndef __REMOVE_SHAPE_COMMAND_H__
#define __REMOVE_SHAPE_COMMAND_H__

#include "command.h"

#include "shape.h"

#include <vector>


namespace tubs::ui
{


class RemoveShapeCommand : public Command
{
public:
    RemoveShapeCommand(std::vector<model::Shape*>& shapes, int shapeNumber, model::Observer* observer);

    virtual void execute();

    virtual void undo();

    virtual void redo();

private:
    std::vector<model::Shape*>& shapes;
    int shapeNumber;

    model::Shape* shape;
    model::Observer* observer;
};


}

#endif