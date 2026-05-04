#include "point.hpp"
#include "shapes/triangle.hpp"
#include <vector>
#include "draw.hpp"

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

void Triangle::draw() {
    std::vector<Point> points = {A, B, C, A};
    draw_picture(points);
}

