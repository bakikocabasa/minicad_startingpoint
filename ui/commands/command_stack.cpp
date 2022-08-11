#include "command_stack.h"

#include <cstdint>
#include <string>

#include "logger.h"

namespace tubs::ui
{

void CommandStack::execute(Command* command) {
    command->execute();

    // TODO: manipulate undo / redo stack here
    // ...

    print("CommandStack::exeucte()");
}

void CommandStack::undo() {
    if (undoStack.empty())
        return;

    // TODO: manipulate undo / redo stack here
    // ...

    print("CommandStack::undo()");
}

void CommandStack::redo() {
    if (redoStack.empty())
        return;

    // TODO: manipulate undo / redo stack here
    // ...

    print("CommandStack::redo()");
}

void CommandStack::print(std::string message) {
    Logger::getInstance().print(message);
    Logger::getInstance().print("Undo Stack size: " + std::to_string(undoStack.size()));
    Logger::getInstance().print("Redo Stack size: " + std::to_string(redoStack.size()));
}

}
