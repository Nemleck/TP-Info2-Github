#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"

struct Circle {
	double radius;
	Point center;
	
	/*Initializer (Circle)
	Creates a new Circle instance.
	@param r : type = double : the circle's radius
	@param c : type = Point : the circle's center point
	@return Circle : the circle of center point c and radius r
	*/
	Circle(double r, Point c = Point());
	
	/*circumference method (Circle)
	Computes the circumference of the current circle.
	@param: None
	@return: double : the circle's circumference
	*/
	double circumference();
	
	/*area method (Circle)
	Computes the area of the current circle.
	@param: None
	@return: double : the circle's area
	*/
	double area();
	
	/*draw method (Circle)
	Draws the current circle using the draw_picture fubnction found in draw.hpp, itself using the CTurtle Library.
	@param: None
	@return: None
	*/
	void draw();
	
	/*translate method (Circle)
	Operates a translation of the current circle by a vector (the center is moved by the vector).
	@param: T : type = Point : the translation vector, implemented in the same way as points are.
	@return: None
	*/
	void translate(Point T);
	
	/*resize method (Circle)
	Resizes the current circle by a ratio.
	@param: ratio : type = double : the resize ratio.
	@return: None
	*/
	void resize(double ratio);
	
	/*equals method (Circle)
	Checks if the current circle is equal to another (same center point and same radius)
	@param: ratio : type = double : the resize ratio.
	@return: bool : true if they are equals, false otherwise
	*/
	bool equals(Circle circle);
	
};

#endif // CIRCLE_HPP