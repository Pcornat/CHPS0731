//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"
#include "rayon.h"

bool Sphere::calculIntersection(Rayon* rayon, std::vector<Intersection>* I) {
	return false;
}

Sphere::Sphere(const float x, const float y, const float z) : origin(x, y, z) {}

Sphere::Sphere(const float x, const float y, const float z, const glm::vec3& color) : Objet(color), origin(x, y, z) {
}
