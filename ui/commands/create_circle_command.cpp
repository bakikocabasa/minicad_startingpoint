#include "create_circle_command.h"

#include "circle.h"

#include "logger.h"

namespace tubs::ui
{

CreateCircleCommand::CreateCircleCommand(std::vector<model::Shape*>& shapes, int x, int y, int radius, model::Observer* observer)
    : shapes(shapes), x(x), y(y), radius(radius), observer(observer) {}

void CreateCircleCommand::execute() {
    shape = new model::Circle(x, y, radius, observer);
    shapes.push_back(shape);

    observer->update();
}

void CreateCircleCommand::undo() {
    shape = shapes.back();
    shapes.pop_back();

    model::Shape::counter--;

    observer->update();
}

void CreateCircleCommand::redo() {
    shapes.push_back(shape);

    model::Shape::counter++;

    observer->update();
}

}
