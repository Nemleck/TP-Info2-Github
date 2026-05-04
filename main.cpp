#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>


int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	Point A(0,0);
	Point C(200,200);
	Square S(A, C);
	std::cout << S.side()<<std::endl;
	std::cout << S.perimeter()<<std::endl;
	std::cout << S.area()<<std::endl;
	
	Point pt=S.center();
	std::cout << pt.x <<"  " <<pt.y << std::endl;
	
	Point T =
	
	// Draw the picture by connecting the points
	draw_picture(points);
	S.draw();
	
	return 0;
}
