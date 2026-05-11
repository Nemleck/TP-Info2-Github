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
    Point A(10,20); // Right Angled Triangle 3-4-5
    Point B(40,20);
    Point C(10,60);

    Triangle t1(A, B, C);

    Point D(-10,10); // Isosceles Triangle, centered in (0;0)
    Point E(20,0);
    Point F(-10,-10);

    Triangle t2(D, E, F);

    Point G(10,0); // Equilateral Triangle
    Point H(-10,0);
    Point I(0,10*sqrt(2));
    
    Triangle t3(G, H, I);

    assert(t1.perimeter() == 120);
    assert(t1.area() == 60);
    assert(t1.isRightAngled());

    t1.translate(E);

    assert(t1.A.x == 20);
    assert(t1.B.y == 40);
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
    assert(t2.A.x == -20);
    assert(t2.A.y == -20);

    t1.rotate(M_PI);
    Point t1Center = t2.center();
    assert(t1Center.x == 0 && t1Center.y == 0);
    assert(t1.A.x == 40 && t1.A.y == 60);

    t1.draw();

    assert(!t2.equals(t1));
    assert(!t3.equals(t1));
    assert(t3.equals(t3));
    assert(t1.equals(t1));

    Circle inscribed = t3.inscribedCircle();
    assert(inscribed.center.x == 0 && abs(inscribed.center.y - 5.8) < 0.1);

    Circle circumscribed = t1.circumscribedCircle();
    assert(circumscribed.center.x == 25 && circumscribed.center.y == 40);
    assert(circumscribed.radius == 25);
	
    std::cout << "Tests of triangle passed" << std::endl;
}

void testsSquare() {
    Point A(10,10);
    Point B(-10,-10);
    Point C(-30,-30);

    Square s1(A,B); // Square centered in (0;0)
    Square s2(A,C); // Square centered in (-1;-1)
    assert(s1.side() == 20);
    assert(s1.perimeter() == 80);
    assert(s1.area() == 40);
    
    Point center1 = s1.center();
    assert(center1.x == 0 && center1.y == 0);

    s1.draw();
    s1.translate(A);
    s1.draw();

    assert(s1.A.x == 20 && s1.A.y == 20);
    assert(s1.C.x == 0 && s1.C.y == 0);
    
    center1 = s1.center();
    assert(center1.x == 10 && center1.y == 10);

    s1.resize(2);
    center1 = s1.center();
    assert(center1.x == 10 && center1.y == 10);

    assert(s1.B.x == -10 && s1.B.y == -10);
    assert(s1.equals(s1));
    assert(!s1.equals(s2));

    s1.rotate(M_PI/4);
    s1.draw();

    Circle inscribed = s2.inscribedCircle();
    assert(inscribed.center.x == -10 && inscribed.center.y == -10);
    assert(inscribed.radius == 20);

    Circle circumscribed = s2.circumscribedCircle();
    assert(circumscribed.center.x == -10 && circumscribed.center.y == -10);
    assert(abs(circumscribed.radius - 20*sqrt(2)) < 0.01);

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