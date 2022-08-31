
#include "remove_shape_command.h"

#include "shape.h"

#include "logger.h"


namespace tubs::ui
{

RemoveShapeCommand::RemoveShapeCommand(std::vector<model::Shape*>& shapes, int shapeNumber, model::Observer* observer)
    : shapes(shapes), shapeNumber(shapeNumber), observer(observer) {}

void RemoveShapeCommand::execute() {
    Logger::getInstance().print("RemoveShapeCommand::execute()");
    shape = shapes[shapeNumber];
    shapes.erase(shapes.begin() + shapeNumber);

    observer->update();
}

void RemoveShapeCommand::undo() {
    shapes.push_back(shape);

    observer->update();
}

void RemoveShapeCommand::redo() {
    shape = shapes.back();
    shapes.pop_back();

    observer->update();
}

}
