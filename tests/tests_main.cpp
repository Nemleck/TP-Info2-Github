#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include "tests_main.hpp"
#include <vector>
#include <cassert>

#define _USE_MATH_DEFINES
#include <cmath>

void testsTriangle() {
    Point A(1,2); // Right Angled Triangle 3-4-5
    Point B(4,2);
    Point C(1,6);

    Triangle t1(A, B, C);

    Point D(-1,1); // Isosceles Triangle, centered in (0;0)
    Point E(2,0);
    Point F(-1,-1);

    Triangle t2(D, E, F);

    Point G(1,0); // Equilateral Triangle
    Point H(-1,0);
    Point I(0,sqrt(2));
    
    Triangle t3(G, H, I);

    assert(t1.perimeter() == 12);
    assert(t1.area() == 6);
    assert(t1.isRightAngled());

    t1.translate(E);

    assert(t1.A.x == 2);
    assert(t1.B.y == 4);
    assert(t1.isRightAngled());
    assert(!t2.isIsoceles());

    Point t2Center = t2.center();
    assert(t2Center.x == 0 && t2Center.y == 0);

    assert(t2.isIsoceles());
    assert(!t2.isRightAngled());

    t2.resize(2);
    t2Center = t2.center();
    assert(t2Center.x == 0 && t2Center.y == 0);
    assert(t2.A.x == -2);
    assert(t2.A.y == -2);

    t1.rotate(M_PI);
    Point t1Center = t2.center();
    assert(t1Center.x == 0 && t1Center.y == 0);
    assert(t1.A.x == 4 && t1.A.y == 6);

    assert(!t2.equals(t1));
    assert(!t3.equals(t1));
    assert(t3.equals(t3));
    assert(t1.equals(t1));

    Circle inscribed = t3.inscribedCircle();
    assert(inscribed.center.x == 0 && abs(inscribed.center.y - 0.58) < 0.01)

    Circle circumscribed = t1.circumscribedCircle();
    assert(circumscribed.center.x == 2.5 && circumscribed.center.y == 4);
    assert(circumscribed.radius == 2.5);
}

void testsSquare() {
}

void testsCircle() {
}