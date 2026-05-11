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
	
	Point Z(0,0);
	Point Y(200,200);
	Square S2(Z, Y);
	
	std::cout << "cote: " << S.side() << std::endl;
	std::cout << "perimetre:" << S.perimeter() << std::endl;
	std::cout << "aire: " << S.area() << std::endl;
	
	
	if(S.equals(S2)){std::cout << "S et S2 sont egaux" << std::endl;}
	
	Point pt=S.center();
	std::cout << "centre: abscisse " << pt.x << " et ordonnee " << pt.y << std::endl;



	// Draw the picture by connecting the points
	draw_picture(points);
		S.draw();
	

	S.resize(2.0);
		S.draw();
	
	Point vecteur(30,60);
	S.translate (vecteur);
		S.draw();
		
	S.rotate(1);
	S.draw();



	return 0;
}
