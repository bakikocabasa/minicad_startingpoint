#ifndef shape_h
#define shape_h

#include "point.h"

namespace tubs::ui {
    class Canvas;
}

namespace tubs::model
{

class Shape;

class Observer {
public:
    virtual ~Observer() {}
    virtual void update() = 0;
};

class Shape
{
public:
    Shape(int x, int y, Observer* observer);
    virtual ~Shape() = default;

    virtual void draw(ui::Canvas* win) const = 0;
    virtual void translate(float dx, float dy);
    // TODO: add a scale method here. This method must be pure virtual and implemented in the specific shapes.
    // ...

    static int counter;

protected:
    Point center;

    int id;
    Observer* observer;
};


}

#endif
