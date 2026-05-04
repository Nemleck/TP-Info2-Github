#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath>
#include <vector>
#include "draw.hpp"

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){
	double side = A.x-C.x;
	side = std::abs(side);
	return side;
}


double Square::perimeter(){
	return side()*4;
}
	
double Square::area(){
	return side()*side();
}

Point Square::center(){
	return Point((A.x+C.x)/2,(A.y+C.y)/2);
}


void Square::draw(){
	std::vector<Point> points = {A, Point(C.x,A.y), C, Point(A.x,C.y), A};
	draw_picture(points);
}

void Square::translate(Point T){
	A.x=T.x;
	A.y=T.y;
	C.y=T.y;
	C.y=T.y;
}