//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"

bool Plan::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int rec) {
	float denom = glm::dot(this->normal, rayon.Vect());
	if (denom > std::numeric_limits<float>::epsilon()) {
		glm::vec3 vecDistOrigPlan = this->orig - rayon.Orig();
		float dist = glm::dot(vecDistOrigPlan, this->normal)/denom;
		I.emplace_back(dist, this->color, this);
		return (dist >= 0);
	}
	return false;
}

Plan::Plan(const float r, const float g, const float b, float xOrig, float yOrig, float zOrig, float x, float y, float z) : Objet(r, g, b),
																									 orig(xOrig, yOrig, zOrig),
																									 normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}

Plan::Plan(Material* material, float xOrig, float yOrig, float zOrig, float x, float y, float z) : Objet(material), orig(xOrig, yOrig, zOrig),
																			normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}

Plan::Plan(float xOrig, float yOrig, float zOrig, float x, float y, float z) : orig(xOrig, yOrig, zOrig), normal(x, y, z) {
	this->normal = glm::normalize(this->normal);
}
