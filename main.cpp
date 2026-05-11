#define _USE_MATH_DEFINES

#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

int main() {
	
	Circle c0 = Circle(100,Point(0,0));
	Circle c1 = Circle(100,Point(0,0));
	Circle c2 = Circle(100,Point(50,50));
	Circle c3 = Circle(50,Point(50,50));
	Point vector = Point(50,50);
	double ratio = 0.5;



	c0.draw();
	c1.draw();
	c2.draw();
	c3.draw();
	assert(c0.circumference()==400*M_PI);
	std::cout << "test circonference passed" << std::endl;
	assert(c0.area()==40000*M_PI);
	std::cout << "test area passed" << std::endl;
	assert(c0.equals(c1));
	std::cout << "test equals passed" << std::endl;
	c0.translate(vector);
	assert(c0.equals(c2));
	std::cout << "test translate passed" << std::endl;
	c0.resize(ratio);
	assert(c0.equals(c3));
	std::cout << "test resize passed" << std::endl;
	
	
	return 0;
}
