#ifndef __SCALE_COMMAND_H__
#define __SCALE_COMMAND_H__

#include "command.h"

#include "shape.h"
#include <vector>

namespace tubs::ui
{


class ScaleShapeCommand : public Command
{
public:
    ScaleShapeCommand(model::Shape* shape,double scaling_coeff);

    virtual void execute();

    virtual void undo();

    virtual void redo();

private:
    model::Shape* shape;
    double scaling_coeff=1.0; //initialized with 1 since 1 is the passive coeff for multiplication

    
};


}

#endif