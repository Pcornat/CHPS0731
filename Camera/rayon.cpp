#include <algorithm>
#include "rayon.h"
#include "objet.h"

glm::vec3 Rayon::Lancer(const Scene& sc, int complexite) const {
	glm::vec3 res(0);//retourne noir de base
	if (complexite == 0) return res;
	std::vector<Intersection> I;
	for (auto objet : sc.Objets) {
		objet->calculIntersection(*this, sc, I, complexite);
	}
	if (!I.empty()) {
		std::sort(I.begin(), I.end());
		//res = I.at(0).obj->getColor();
		const Intersection& intersection = I.at(0);
		res = intersection.getObj()->getMaterial()->computeColour(I.at(0), this->orig + this->vect * intersection.getDist(), sc, *this,
																  complexite - 1);
	}
	return res;
}

Rayon::Rayon(const glm::vec3& orig, const glm::vec3& vect) : orig(orig), vect(vect) {}

bool Rayon::shadowRay(const Scene& sc, float distLum, int complexite) {
	std::vector<Intersection> I;
	for (auto objet : sc.Objets) {
		objet->calculIntersection(*this, sc, I, complexite);
	}
	if (!I.empty()) {
		std::sort(I.begin(), I.end());
		return I.at(0).getDist() < distLum; //true = shadow, false : light
	}
	return false;
}