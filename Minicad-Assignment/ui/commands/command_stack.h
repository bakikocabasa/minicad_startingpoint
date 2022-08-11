#ifndef command_stack_h
#define command_stack_h

#include <stack>
#include <string>

#include "command.h"

namespace tubs::ui
{

class CommandStack
{
public:
    void execute(Command* command);
    void undo();
    void redo();

private:
    void print(std::string message);

    // The stack container behaves similar to a vector, but the access follows the LIFO (last-in, first-out) pattern.
    // https://en.cppreference.com/w/cpp/container/stack
    std::stack<Command*> undoStack;
    std::stack<Command*> redoStack;
};

}

#endif
