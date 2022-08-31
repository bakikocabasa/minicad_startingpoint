#include "upscale_shape_command.h"

#include "logger.h"
#include "shape.h"


namespace tubs::ui
{

UpScaleShapeCommand::UpScaleShapeCommand(model::Shape* shape,double scaling_coeff)
    :shape(shape), scaling_coeff(scaling_coeff) {}

void UpScaleShapeCommand::execute() {
    Logger::getInstance().print("ScaleShapesCommand::execute()");
    shape->scale(scaling_coeff);
    
}

void UpScaleShapeCommand::undo() {
    shape->scale(1.0/scaling_coeff);
}

void UpScaleShapeCommand::redo() {
    shape->scale(scaling_coeff);
}


}
