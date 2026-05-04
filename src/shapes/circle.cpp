#define _USE_MATH_DEFINES

#include "point.hpp"
#include "draw.hpp"
#include "shapes/circle.hpp"
#include <cmath>



Circle::Circle(double r, Point c) : radius(r), center(c) {};

void Circle::draw()
{
    std::vector<Point> points;
    for (int a = 0 ; a <= 360 ; a+=2)
    {
        Point point = Point(center.x+radius*cos((a*M_PI)/180),center.y+radius*sin((a*M_PI)/180));
        points.push_back(point);
    }
    draw_picture(points);
}
