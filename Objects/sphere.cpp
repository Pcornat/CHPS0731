//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"
#include <intersection.h>
#include <material.h>


bool Sphere::calculIntersection(const Rayon &rayon, [[maybe_unused]] const Scene &sc, std::vector<Intersection> &I, [[maybe_unused]] int rec) {
	//Équation : a = 1, b = 2* (D.(O - C)), c =|O - C|² - R²
	float dist = 0.0f;
	if (!glm::intersectRaySphere(rayon.getOrigine(), rayon.vectDirection(), this->center, this->radius, dist)) {
		return false;
	}
	glm::vec3 point = rayon.getOrigine() + (rayon.vectDirection() * dist), norm = glm::normalize(
			(point - this->center) / glm::length(point - this->center));
	I.emplace_back(dist, norm, this);
	return true;
}

Sphere::~Sphere() {
	delete material;
}

Sphere::Sphere(Material *material, glm::vec3 &&center, int radius) : Objet(material), center(center), radius(radius) {}

Sphere::Sphere(Material *material, const glm::vec3 &center, int radius) : Objet(material), center(center),
																		  radius(radius) {}

void Sphere::fromJson(const FromJson::json &objet) const {

}