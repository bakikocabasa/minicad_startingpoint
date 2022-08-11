#include "create_triangle_command.h"

#include "triangle.h"

#include "logger.h"

namespace tubs::ui
{

CreateTriangleCommand::CreateTriangleCommand(std::vector<model::Shape*>& shapes, int x, int y, int length, model::Observer* observer)
    : shapes(shapes), x(x), y(y), length(length), observer(observer) {}

void CreateTriangleCommand::execute() {
    shape = new model::Triangle(x, y, length, observer);
    shapes.push_back(shape);

    observer->update();
}

void CreateTriangleCommand::undo() {
    shape = shapes.back();
    shapes.pop_back();

    model::Shape::counter--;

    observer->update();
}

void CreateTriangleCommand::redo() {
    shapes.push_back(shape);

    model::Shape::counter++;

    observer->update();
}

}
