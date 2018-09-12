//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"
#include "rayon.h"

/**
 * \todo finish this methode : it will compute the intersection between the sphere and the ray. It'll be difficult not to use glm::intersect T-T
 * @param rayon the ray to use to compute the intersection.
 * @param I
 * @return
 */
bool Sphere::calculIntersection(Rayon& rayon, std::vector<Intersection>& I) {
	//Équation : a = 1, b = 2* (D.(O - C)), c =|O - C|² - R²
	glm::vec3 OCVec = rayon.Orig() - this->center;
	float a = 1,
			b = 2 * glm::dot(rayon.Vect(), OCVec),
			c = glm::dot(OCVec, OCVec) - this->radius * this->radius, delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return false;
	if (delta == 0) {
		float dist = -0.5f * b / a;
		glm::vec3 point = rayon.Orig() + (rayon.Vect() * dist), norm = glm::normalize(point - this->center);
		I.emplace_back(dist, norm, this);
		return true;
	}
	float q = (b > 0) ? -0.5f * (b + sqrtf(delta)) : -0.5f * (b - sqrtf(delta)),
			x0 = q / a,
			x1 = c / q;
	if (x0 > x1) std::swap(x0, x1);
	glm::vec3 point = rayon.Orig() + (rayon.Vect() * x0), norm = glm::normalize(x0 - this->center);
	I.emplace_back(x0, norm, this);
	return true;
}

Sphere::Sphere(const float x, const float y, const float z, const int r) : center(x, y, z), radius(r) {}

Sphere::Sphere(const float x, const float y, const float z, const int radius, const float r, const float g,
			   const float b) : Objet(r, g, b),
								center(x, y, z),
								radius(radius) {}
