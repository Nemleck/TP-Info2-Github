#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include "tests_main.hpp"

#include <vector>

#define NDEBUG
#include <cassert>
#include <iostream>

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

    t1.draw();

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

    t1.draw();

    assert(!t2.equals(t1));
    assert(!t3.equals(t1));
    assert(t3.equals(t3));
    assert(t1.equals(t1));

    Circle inscribed = t3.inscribedCircle();
    assert(inscribed.center.x == 0 && abs(inscribed.center.y - 0.58) < 0.01);

    Circle circumscribed = t1.circumscribedCircle();
    assert(circumscribed.center.x == 2.5 && circumscribed.center.y == 4);
    assert(circumscribed.radius == 2.5);
	
    std::cout << "Tests of triangle passed" << std::endl;
}

void testsSquare() {
    Point A(1,1);
    Point B(-1,-1);
    Point C(-3,-3);

    Square s1(A,B); // Square centered in (0;0)
    Square s2(A,C); // Square centered in (-1;-1)
    assert(s1.side() == 2);
    assert(s1.perimeter() == 8);
    assert(s1.area() == 4);
    
    Point center1 = s1.center();
    assert(center1.x == 0 && center1.y == 0);

    s1.draw();
    s1.translate(A);
    s1.draw();

    assert(s1.A.x == 2 && s1.A.y == 2);
    assert(s1.C.x == 0 && s1.C.y == 0);
    
    center1 = s1.center();
    assert(center1.x == 1 && center1.y == 1);

    s1.resize(2);
    center1 = s1.center();
    assert(center1.x == 1 && center1.y == 1);

    assert(s1.B.x == -1 && s1.B.y == -1);
    assert(s1.equals(s1));
    assert(!s1.equals(s2));

    s1.rotate(M_PI/4);
    s1.draw();

    Circle inscribed = s2.inscribedCircle();
    assert(inscribed.center.x == -1 && inscribed.center.y == -1);
    assert(inscribed.radius == 2);

    Circle circumscribed = s2.circumscribedCircle();
    assert(circumscribed.center.x == -1 && circumscribed.center.y == -1);
    assert(abs(circumscribed.radius - 2*sqrt(2)) < 0.001);

	std::cout << "Tests of square passed" << std::endl;
}

void testsCircle() {
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
	assert(c0.area()==40000*M_PI);
	assert(c0.equals(c1));
	c0.translate(vector);
	assert(c0.equals(c2));
	c0.resize(ratio);
	assert(c0.equals(c3));

	std::cout << "Tests of circle passed" << std::endl;
}