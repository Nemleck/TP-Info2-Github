#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>


int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	Point P(0,0);
	Point Q(100,0);
	Point R(50,100);
	// Draw the picture by connecting the points
	draw_picture(points);
	Triangle t(P,Q,R);
	t.draw();
	return 0;
}
