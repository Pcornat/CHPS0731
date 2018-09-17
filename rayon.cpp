#include <algorithm>
#include "rayon.h"
#include "objet.h"

glm::vec3 Rayon::Lancer(Scene& sc, int current) const {
	glm::vec3 res = glm::vec3(0);//retourne noir de base
	if (current == 0) return res;
	bool intersect = false;
	std::vector<Intersection> I;
	for (auto&& objet : sc.Objets) {
		intersect = objet->calculIntersection(*this, sc, I);
	}
	//WIP : integrating light inside the project.
	if (intersect) {
		std::sort(I.begin(), I.end());
		//res = I.at(0).obj->getColor();
		res = I.at(0).getNormal();
	}
	return res;
}