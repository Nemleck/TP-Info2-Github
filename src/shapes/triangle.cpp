#include "point.hpp"
#include "shapes/triangle.hpp"
#include <vector>
#include "draw.hpp"
#include <cmath>
#include <iostream>
Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

void Triangle::draw() {
    std::vector<Point> points = {A, B, C, A};
    draw_picture(points);
}

double dist(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double Triangle::perimeter(){
	return dist(A,B) + dist(B,C) + dist (C,A);
}

double Triangle::area(){
	return (dist(A,B)*dist(dist(A,B)/2,B)/2);
}

Point Triangle::center(){
	
	return Point((A.x+B.x+C.x)/3.0, (A.y+B.y+C.y)/3.0);
	
}

void Triangle::translate(Point T){
	A.x += T.x;
	A.y += T.y;
	C.x += T.x;
	C.y += T.y;
	B.x += T.x;
	B.y += T.y;
}

//A' = centre + (A-centre)*ratio
void Triangle::resize(double ratio){
	Point M = center();
	
	A.x = M.x + (A.x-M.x) * ratio;
	A.y = M.y + (A.y-M.y) * ratio;
	
	B.x = M.x + (B.x-M.x) * ratio;
	B.y = M.y + (B.y-M.y) * ratio;
	
	C.x = M.x + (C.x-M.x) * ratio;
	C.y = M.y + (C.y-M.y) * ratio;
}


void Triangle::rotate(double angle) {
	Point M = center();
	double tempA = A.x;
	
	A.x = M.x + (tempA-M.x)*cos(angle)- (A.y -M.y)*sin(angle);
	A.y = M.y + (tempA-M.x)*sin(angle)+ (A.y -M.y)*cos(angle);
	
	double tempB = B.x;
	B.x = M.x + (tempB-M.x)*cos(angle)- (B.y -M.y)*sin(angle);
	B.y = M.y + (tempB-M.x)*sin(angle)+ (B.y -M.y)*cos(angle);
	
	double tempC = C.x;
	C.x = M.x + (tempC-M.x)*cos(angle)- (C.y -M.y)*sin(angle);
	C.y = M.y + (tempC-M.x)*sin(angle)+ (C.y -M.y)*cos(angle);
}



bool Triangle::isEquilateral(){
	double ab= dist(A,B), bc=dist(B,C), ca=dist(C,A);
	return ((std::abs(ab - bc) < 1e-9) and (std::abs(bc - ca) < 1e-9));
}

bool Triangle::isIsoceles(){
	double ab= dist(A,B), bc=dist(B,C), ca=dist(C,A);
	return  ( (std::abs(ab)== std::abs(bc)) or (std::abs(ab)== std::abs(ca)) or (std::abs(bc)== std::abs(ca)));
}


bool Triangle::equals(Triangle triangle) {
	return( 
	((std::abs(A.x - triangle.A.x) < 1e-9) and (std::abs(A.y - triangle.A.y) < 1e-9)) and
	((std::abs(B.x - triangle.B.x) < 1e-9) and (std::abs(B.y - triangle.B.y) < 1e-9)) and
	((std::abs(C.x - triangle.C.x) < 1e-9) and (std::abs(C.y - triangle.C.y) < 1e-9)));
}

bool Triangle::isRightAngled(){
	double ab2 = std::pow (dist(A,B),2);
	double bc2 = std::pow (dist(B,C),2);
	double ca2 = std::pow (dist(C,A),2);
	return (std::abs(ab2 + bc2 - ca2) < 1e-9 or std::abs(ab2 + ca2 - bc2) < 1e-9 or std::abs(bc2 + ca2 - ab2) < 1e-9);
}



Circle Triangle::inscribedCircle(){
    double a = dist(B, C); 
    double b = dist(A, C); 
    double c = dist(A, B); 
    double p = perimeter();
    

    double ix = (a * A.x + b * B.x + c * C.x) / p;
    double iy = (a * A.y + b * B.y + c * C.y) / p;
    Point incentre(ix, iy);
    
    double rayon = area() / (p / 2.0);
    return  Circle(rayon, incentre);
}