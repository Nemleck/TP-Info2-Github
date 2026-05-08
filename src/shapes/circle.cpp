
#define _USE_MATH_DEFINES // used for pi

#include "point.hpp"
#include "draw.hpp"
#include "shapes/circle.hpp"
#include <cmath> // used for cos and sin


/*Initializer (Circle)
Creates a new Circle instance.
@param r : type = double : the circle's radius
@param c : type = Point : the circle's center point
@return Circle : the circle of center point c and radius r
*/
Circle::Circle(double r, Point c) : radius(r), center(c) {};

/*circumference method (Circle)
Computes the circumference of the current circle.
@param: None
@return: double : the circle's circumference
*/
double Circle::circumference()
{
    return 2*M_PI*radius;
}

/*area method (Circle)
Computes the area of the current circle.
@param: None
@return: double : the circle's area
*/
double Circle::area()
{
    return M_PI*pow(radius,2);
}

/*draw method (Circle)
Draws the current circle using the draw_picture fubnction found in draw.hpp, itself using the CTurtle Library.
@param: None
@return: None
*/
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

/*translate method (Circle)
Operates a translation of the current circle by a vector (the center is moved by the vector).
@param: T : type = Point : the translation vector, implemented in the same way as points are.
@return: None
*/
void Circle::translate(Point T)
{
    center.x += T.x;
    center.y += T.y;
}

/*resize method (Circle)
Resizes the current circle by a ratio.
@param: ratio : type = double : the resize ratio.
@return: None
*/
void Circle::resize(double ratio)
{
    radius *= ratio;
}

/*equals method (Circle)
Checks if the current circle is equal to another (same center point and same radius)
@param: ratio : type = double : the resize ratio.
@return: bool : true if they are equals, false otherwise
*/
bool Circle::equals(Circle circle)
{
    return radius == circle.radius && centre.x == circle.x && centre.y == circle.y ;
}