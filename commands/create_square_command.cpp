#include "create_square_command.h"

#include "square.h"

#include "logger.h"

namespace tubs::ui
{

CreateSquareCommand::CreateSquareCommand(std::vector<model::Shape*>& shapes, int x, int y, int length, model::Observer* observer) // change the inputs regarding square
    : shapes(shapes), x(x), y(y), length(length), observer(observer) {}

void CreateSquareCommand::execute() {
    shape = new model::Square(x, y, length, observer);
    shapes.push_back(shape);

    observer->update();
}

void CreateSquareCommand::undo() {
    shape = shapes.back();
    shapes.pop_back();

    model::Shape::counter--;

    observer->update();
}

void CreateSquareCommand::redo() {
    shapes.push_back(shape);

    model::Shape::counter++;

    observer->update();
}

}
