#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>

int main() {
	
	// Define points in a vector
	Point A(0,0);
	Point B(100,0);
	Point C(50,100);
	// Draw the picture by connecting the points
	
	Triangle t(A,B,C);
	Triangle t2(A,B,C);
	t.draw();
	if (t.equals(t2)) {
        std::cout << "REUSSI : t est bien egal a t2." << std::endl;
    }
	std::cout << t.perimeter()<< std::endl ;
	std::cout << t.area()<< std::endl ;
	Point pt = t.center();
	std::cout<<pt.x<<" "<<pt.y<<std::endl;
	Point vecteur(30, 60);
	t.translate(vecteur); // Déplace le triangle
	t.draw();             // Dessine le triangle déplacé
	t.resize(2.0);
	t.draw();
	if (t.isEquilateral()) {
        std::cout << "Le triangle est equi." << std::endl;
    }
	
	if (t.isIsoceles()) {
        std::cout << "Le triangle est iso." << std::endl;
    }
	
	t.rotate(1.57);
	t.draw();
	
	
	
	if (t.isRightAngled()) {
        std::cout << "Le triangle est rectangle." << std::endl;
    }
	
	Circle inscrit = t.inscribedCircle();

	// On affiche les valeurs numériques du cercle
	std::cout << "Cercle inscrit -> Rayon: " << inscrit.radius 
          << " | Centre: (" << inscrit.center.x << ", " << inscrit.center.y << ")" 
          << std::endl;
		  
		  
	// 1. Calcul du cercle circonscrit
	Circle circonscrit = t.circumscribedCircle();

	// 2. Affichage des résultats
	std::cout << "--- Cercle Circonscrit ---" << std::endl;
	std::cout << "Rayon : " << circonscrit.radius << std::endl;
	std::cout << "Centre : (" << circonscrit.center.x << ", " << circonscrit.center.y << ")" << std::endl;

	// 3. Optionnel : dessiner le cercle si la classe Circle a une méthode draw
	// circonscrit.draw();
	return 0;
}

