//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"
#include "rayon.h"

bool Sphere::calculIntersection(Rayon* rayon, std::vector<Intersection>* I) {
	float sqRad = radius * radius, inter = glm::length(rayon->Orig() - this->origin), sqNormOC = inter * inter;
	inter = glm::dot(rayon->Vect(), (rayon->Orig() - this->origin) * (rayon->Orig() - this->origin));
	float firstElement = inter * inter, delta = (firstElement - sqNormOC + sqRad);
	if (delta < 0.0f) return false;
	Intersection intersection;
	float membreGaucheDelta = -(glm::dot(rayon->Vect(), (rayon->Orig() - this->origin))),
			sqrtDelta = glm::sqrt(delta);
	if (delta == 0.0f) {

	}
	return true;
}

Sphere::Sphere(const float x, const float y, const float z, const int r) : origin(x, y, z), radius(r) {}

Sphere::Sphere(const float x, const float y, const float z, const int r, const glm::vec3& color) : Objet(color),
																								   origin(x, y, z),
																								   radius(r) {}
