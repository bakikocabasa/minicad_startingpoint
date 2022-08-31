#include "translate_shape_command.h"

#include "logger.h"

namespace tubs::ui
{

TranslateShapeCommand::TranslateShapeCommand(model::Shape* shape, int dx, int dy)
    : shape(shape), dx(dx), dy(dy) {}

void TranslateShapeCommand::execute() {
    Logger::getInstance().print("TranslateShapeCommand::execute()");

    shape->translate(dx, dy);
}

void TranslateShapeCommand::undo() {
    shape->translate(-dx, -dy);
}

void TranslateShapeCommand::redo() {
    shape->translate(dx, dy);
}


}
