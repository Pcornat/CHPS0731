//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/intersect.hpp>

bool Plan::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int rec) {
	/*float denom = glm::dot(this->normal, rayon.Vect());
	if (glm::abs(denom) > std::numeric_limits<float>::epsilon()) {
		glm::vec3 vecDistOrigPlan = this->orig - rayon.Orig();
		float dist = glm::dot(vecDistOrigPlan, this->normal) / denom;
		I.emplace_back(dist, this->color, this);
		return (dist >= 0);
	}
	return false;//*/
	float dist;
	bool intersect = glm::intersectRayPlane(rayon.Orig(), rayon.Vect(), this->orig, this->normal, dist);
	if (intersect) {
		I.emplace_back(dist, this->color, this);
		return true;
	}
	return false;//*/
}

Plan::Plan(float r, float g, float b, float xOrig, float yOrig, float zOrig, float x, float y, float z) : Objet(r, g, b),
																										  orig(xOrig, yOrig,
																											   zOrig),
																										  normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}

Plan::Plan(Material* material, float xOrig, float yOrig, float zOrig, float x, float y, float z) : Objet(material),
																								   orig(xOrig, yOrig, zOrig),
																								   normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}

Plan::Plan(float xOrig, float yOrig, float zOrig, float x, float y, float z) : orig(xOrig, yOrig, zOrig), normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}
