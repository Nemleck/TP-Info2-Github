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

void translate(Point T){
	A.x += T.x;
	A.y += T.y;
	C.x += T.x;
	C.y += T.y;
	B.x += T.x;
	B.y += T.y;
}