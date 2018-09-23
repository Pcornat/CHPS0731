//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"

bool Plan::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int rec) {
	/*
	 * ray.Orig() + ray.Vect() * dist = point of intersection.
	 * so dist = (origin_normal_vec_plan - ray.Orig()) dot normal vect, / denom
	 * denom = ray.Vect() dot normal_vect_plan
	 */
	float denom = glm::dot(this->normal, rayon.Vect());
	if (denom > std::numeric_limits<float>::epsilon()) {
		glm::vec3 vecDistOrigPlan = this->orig - rayon.Orig();
		float dist = glm::dot(vecDistOrigPlan, this->normal) / denom;
		Intersection intersection(dist, this->color, this);
		glm::vec3 point(rayon.Orig() + rayon.Vect() * dist);
		I.push_back(intersection);
		if (dist >= 0)//Preparing for computation of the colour (if phong model or anything else)
			return true;
		else
			return false;
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
