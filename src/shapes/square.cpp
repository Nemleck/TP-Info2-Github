#include "point.hpp"
#include "shapes/square.hpp"
#include <cmath>
#include <vector>
#include "draw.hpp"

using namespace std;

Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side(){
	double side = A.x-C.x;
	side = abs(side);
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
	Point M = center();
	
	Point vect(A.x-M.x, A.y-M.y);
	Point B(M.x-vect.y,M.y+vect.x);
	Point D(M.x+vect.y,M.y-vect.x);
	
	std::vector<Point> points = {A, B, C, D, A};
	draw_picture(points);
}

void Square::translate(Point T){
	A.x+=T.x;
	A.y+=T.y;
	C.x+=T.x;
	C.y+=T.y;
}

void Square::resize(double ratio){
	Point M = center();
	
	A.x=M.x+(A.x-M.x)*ratio;
	A.y=M.y+(A.y-M.y)*ratio;
	C.x=M.x+(C.x-M.x)*ratio;
	C.y=M.y+(C.y-M.y)*ratio;
}


void Square::rotate(double angle){
	Point M = center();
	
	double TempA = A.x;
	double TempC = C.x;
	
	
	A.x= (A.x-M.x)*cos(angle)-(A.y-M.y)*sin(angle)+M.x;
	A.y= (TempA-M.x)*sin(angle)+(A.y-M.y)*cos(angle)+M.y;
	
	C.x= (C.x-M.x)*cos(angle)-(C.y-M.y)*sin(angle)+M.x;
	C.y= (TempC-M.x)*sin(angle)+(C.y-M.y)*cos(angle)+M.y;
}


bool Square::equals(Square square){
	return(((std::abs(A.x-square.A.x)<1e-9)and(std::abs(A.y-square.A.y)<1e-9))and
	((std::abs(C.x-square.C.x)<1e-9)and(std::abs(C.y-square.C.y)<1e-9)));
}

Circle Square::inscribedCircle(){
	 return Circle(side() / 2.0, center());
}

Circle Square::circumscribedCircle(){
    double r = (side() * std::sqrt(2.0)) / 2.0;
    return Circle(r, center());
}