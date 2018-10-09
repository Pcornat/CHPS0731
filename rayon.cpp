#include <algorithm>
#include "rayon.h"
#include "objet.h"

glm::vec3 Rayon::Lancer(const Scene& sc, int complexite) const {
	glm::vec3 res = glm::vec3(0);//retourne noir de base
	if (complexite == 0) return res;
	bool intersect = false;
	std::vector<Intersection> I;
	for (auto&& objet : sc.Objets) {
		intersect = objet->calculIntersection(*this, sc, I, complexite);
	}
	if (intersect) {
		std::sort(I.begin(), I.end());
		//res = I.at(0).obj->getColor();
		res = I.at(0).getNormal();
	}
	return res;
}

Rayon::Rayon(const glm::vec3& orig, const glm::vec3& vect) : orig(orig), vect(vect) {}

bool Rayon::shadowRay(const Scene& sc, float distLum) {
	bool intersect = false;
	std::vector<Intersection> I;
	for (Objet* objet : sc.Objets) {
		intersect = objet->calculIntersection(*this, sc, I, 1);
	}
	if (intersect) {
		std::sort(I.begin(), I.end());
		return I.at(0).getDist() < distLum;
	}
	return false;
}