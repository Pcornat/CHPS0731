//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"

bool Plan::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int rec) {
	float denom = glm::dot(this->normal, rayon.Vect());
	if (denom > std::numeric_limits<float>::epsilon()) {
		//Need the point where the normal is
	}
	return false;
}

Plan::Plan(const float r, const float g, const float b, float distOrig, float x, float y, float z) : Objet(r, g, b),
																									 distOrig(distOrig),
																									 normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}

Plan::Plan(Material* material, float distOrig, float x, float y, float z) : Objet(material), distOrig(distOrig),
																			normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}

Plan::Plan(float distOrig, float x, float y, float z) : distOrig(distOrig), normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}
