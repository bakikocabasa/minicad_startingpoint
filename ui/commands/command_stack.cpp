#include "command_stack.h"

#include <cstdint>
#include <string>

#include "logger.h"

namespace tubs::ui
{

void CommandStack::execute(Command* command) {
    command->execute();

    //Stack that stores the original parameters of the an executed command
    // TODO: manipulate undo / redo stack here
    redoStack.empty(); //clears the redoStack because a new command was just executed
    command->execute();  
    undoStack.push(command);  //stores command in undoStack

    print("CommandStack::exeucte()");
}

void CommandStack::undo() {
    //why undoStack? pre-defined function this.isEmpty
    if (undoStack.empty())
        return;

    // TODO: manipulate undo / redo stack here
    undoStack.top()->undo();  //undo command on the top of the undoStack
    redoStack.push(undoStack.top());  //adds the undone command to the redoStack
    undoStack.pop();  //deletes the last entry of the undoStack

    print("CommandStack::undo()");
}

void CommandStack::redo() {
    if (redoStack.empty())
        return;

    // TODO: manipulate undo / redo stack here
    redoStack.top()->redo();
    undoStack.push(redoStack.top());
    redoStack.pop();

    print("CommandStack::redo()");
}

void CommandStack::print(std::string message) {
    Logger::getInstance().print(message);
    Logger::getInstance().print("Undo Stack size: " + std::to_string(undoStack.size()));
    Logger::getInstance().print("Redo Stack size: " + std::to_string(redoStack.size()));
}

}
