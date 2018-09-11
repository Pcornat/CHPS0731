//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"
#include "rayon.h"

bool Sphere::calculIntersection(Rayon* rayon, std::vector<Intersection>* I) {
	/*
	 * sqRad : rayon au carré (voir formule)
	 * inter : intermédiaire : calcul la norme du vecteur origine du rayon vers centre de la sphère.
	 * sqNormOC : norme au carré du vecteur origine -> centre sphère (||o - c||²)
	 */
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

Sphere::Sphere(const float x, const float y, const float z, const int radius, const float r, const float g,
			   const float b) : Objet(r, g, b),
								origin(x, y, z),
								radius(radius) {}
