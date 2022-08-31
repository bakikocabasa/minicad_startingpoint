#include "downscale_shape_command.h"

#include "logger.h"
#include "shape.h"


namespace tubs::ui
{

DownScaleShapeCommand::DownScaleShapeCommand(model::Shape* shape,double scaling_coeff)
    :shape(shape), scaling_coeff(scaling_coeff) {}

void DownScaleShapeCommand::execute() {
    Logger::getInstance().print("ScaleShapesCommand::execute()");
    shape->scale(1.0/scaling_coeff);
    
}

void DownScaleShapeCommand::undo() {
    shape->scale(scaling_coeff);
}

void DownScaleShapeCommand::redo() {
    shape->scale(1.0/scaling_coeff);
}


}
