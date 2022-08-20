#include "scale_shape_command.h"

#include "logger.h"
#include "shape.h"


namespace tubs::ui
{

ScaleShapeCommand::ScaleShapeCommand(model::Shape* shape,int scaling_coeff)
    :shape(shape), scaling_coeff(scaling_coeff) {}

void ScaleShapeCommand::execute() {
    Logger::getInstance().print("ScaleShapesCommand::execute()");
    shape->scale(scaling_coeff);
    
}

void ScaleShapeCommand::undo() {
    shape->scale(1.0/scaling_coeff);
}

void ScaleShapeCommand::redo() {
    shape->scale(scaling_coeff);
}


}
