#include "rayon.h"
#include <scene.h>
#include <objet.h>
#include <intersection.h>
#include <material.h>
#include <algorithm>

glm::vec3 Rayon::lancer(const Scene &sc, int complexite) const {
	glm::vec3 res(0);//retourne noir de base
	if (complexite == 0) return res;
	std::vector<Intersection> I;
	for (auto *objet : sc.getObjets()) {
		objet->calculIntersection(*this, sc, I, complexite);
	}
	if (!I.empty()) {
		std::sort(I.begin(), I.end());
		//res = I.at(0).obj->getColor();
		const Intersection &intersection = I.at(0);
		res = intersection.getObj()->getMaterial()->computeColour(I.at(0), this->origine + this->direction * intersection.getDist(), sc, *this,
																  complexite - 1);
	}
	return res;
}

Rayon::Rayon(const glm::vec3 &origine, const glm::vec3 &direction) : origine(origine), direction(direction) {}

bool Rayon::shadowRay(const Scene &sc, float distLum, int complexite) {
	std::vector<Intersection> I;
	for (auto *objet : sc.getObjets()) {
		objet->calculIntersection(*this, sc, I, complexite);
	}
	if (!I.empty()) {
		std::sort(I.begin(), I.end());
		return std::isless(I.at(0).getDist(), distLum); //true = shadow, false : light
	}
	return false;
}