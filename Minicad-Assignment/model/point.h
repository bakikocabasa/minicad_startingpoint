#ifndef point_h
#define point_h

namespace tubs::model
{

struct Point
{
    Point(double x, double y);

    void translate(double dx, double dy);

    double x = 0.0;
    double y = 0.0;
};

}

#endif
