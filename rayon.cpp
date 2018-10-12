#include <algorithm>
#include "rayon.h"
#include "objet.h"

glm::highp_dvec3 Rayon::Lancer(const Scene& sc, int complexite) const {
	glm::highp_dvec3 res = glm::highp_dvec3(0);//retourne noir de base
	if (complexite == 0) return res;
	std::vector<Intersection> I;
	for (auto objet : sc.Objets) {
		objet->calculIntersection(*this, sc, I, complexite);
	}
	if (!I.empty()) {
		std::sort(I.begin(), I.end());
		//res = I.at(0).obj->getColor();
		Intersection intersection = I.at(0);
		res = intersection.getObj()->getMaterial()->computeColour(I.at(0), this->orig + this->vect * intersection.getDist(), sc, *this,
																  complexite - 1);
	}
	return res;
}

Rayon::Rayon(const glm::highp_dvec3& orig, const glm::highp_dvec3& vect) : orig(orig), vect(vect) {}

bool Rayon::shadowRay(const Scene &sc, double distLum, int complexite) {
	std::vector<Intersection> I;
	for (auto objet : sc.Objets) {
		objet->calculIntersection(*this, sc, I, complexite);
	}
	if (!I.empty()) {
		std::sort(I.begin(), I.end());
		return I.at(0).getDist() < distLum;
	}
	return false;
}