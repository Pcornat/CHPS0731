#include <algorithm>
#include "rayon.h"
#include "objet.h"

glm::vec3 Rayon::Lancer(Scene& sc, int current) const {
	glm::vec3 res = glm::vec3(0);//retourne noir de base
	if (current == 0) return res;
	Objet* obj;
	bool intersect = false;
	auto I = new std::vector<Intersection>();
	Intersection intersection;
	auto r = new Rayon();
	r->Orig(orig);
	r->Vect(vect);
	for (int i = 0; i < sc.Objets.size(); i++) {
		obj = sc.Objets[i];
		if (obj->calculIntersection(r, I)) {
			intersect = true;
		}
	}
	if (intersect) {
		std::sort(I->begin(), I->end());
		intersection = I->at(0);
		res = intersection.obj->getColor();
		res = intersection.normal;
	}
	delete I;
	delete r;
	return res;
}