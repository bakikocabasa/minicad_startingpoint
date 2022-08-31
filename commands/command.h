#ifndef __COMMAND_H__
#define __COMMAND_H__


namespace tubs::ui
{

class Command
{
public:
    virtual ~Command() {}

    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

}

#endif
