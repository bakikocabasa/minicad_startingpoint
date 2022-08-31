#ifndef __TRANSLATE_COMMAND_H__
#define __TRANSLATE_COMMAND_H__

#include "command.h"

#include "shape.h"


namespace tubs::ui
{


class TranslateShapeCommand : public Command
{
public:
    TranslateShapeCommand(model::Shape* shape, int dx, int dy);

    virtual void execute();

    virtual void undo();

    virtual void redo();

private:
    model::Shape* shape;
    int dx = 0;
    int dy = 0;
};


}

#endif