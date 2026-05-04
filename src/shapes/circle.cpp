#define _USE_MATH_DEFINES

#include "point.hpp"
#include "draw.hpp"
#include "shapes/circle.hpp"
#include <cmath>



Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference()
{
    return 2*M_PI*radius;
}

double Circle::area()
{
    return M_PI*pow(radius,2);
}

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

void Circle::translate(Point T)
{
    center = T;
}

void Circle::resize(double ratio)
{
    radius *= ratio;
}

bool Circle::equals(Circle circle)
{
    return radius == circle.radius && centre.x == circle.x && centre.y == circle.y ;
}