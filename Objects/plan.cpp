//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"
#include "phong.h"

/**
 * @param rayon
 * @param scene
 * @param I
 * @param rec
 */
bool Plan::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int rec) {
	/*double denom = glm::dot(this->normal, rayon.vectDirection());
	if (glm::abs(denom) > std::numeric_limits<double>::epsilon()) {
		glm::vec3 vecDistOrigPlan = this->orig - rayon.getOrigine();
		double dist = glm::dot(vecDistOrigPlan, this->normal) / denom;
		I.emplace_back(dist, this->color, this);
		return (dist >= 0);
	}
	return false;//*/
	float dist = 0.0f;
	if (!glm::intersectRayPlane(rayon.getOrigine(), rayon.vectDirection(), this->orig, this->normal, dist)) {
		return false;
	}
	I.emplace_back(dist, this->normal, this);
	return true;//*/
}

Plan::Plan(Material* material, const glm::vec3& orig, const glm::vec3& normal) : Objet(material), orig(orig),
																				 normal(glm::normalize(normal)) {}

Plan::Plan(Material* material, glm::vec3&& orig, glm::vec3&& normal) : Objet(material), orig(orig), normal(glm::normalize(normal)) {}

Plan::~Plan() {
	delete material;
}

void Plan::fromJson(const FromJson::json& objet) const {

}