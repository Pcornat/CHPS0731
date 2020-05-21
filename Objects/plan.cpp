//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY
#define GLM_ENABLE_EXPERIMENTAL

#include <glm/geometric.hpp>
#include <glm/gtx/intersect.hpp>

#include <intersection.h>
#include <Camera/rayon.h>
#include <Materials/phong.h>

bool Plan::calculIntersection(const Rayon &rayon,
							  [[maybe_unused]] const Scene &scene,
							  std::vector<Intersection> &I,
							  [[maybe_unused]] const int rec) const {
	float dist = 0.0f;
	if (!glm::intersectRayPlane(rayon.getOrigine(), rayon.vectDirection(), this->orig, this->normal, dist)) {
		return false;
	}
	I.emplace_back(dist, this->normal, this);
	return true;
}

Plan::Plan(Material *material, const glm::vec3 &orig, const glm::vec3 &normal) : Objet(material), orig(orig),
																				 normal(glm::normalize(normal)) {}

Plan::Plan(Material *material, glm::vec3 &&orig, glm::vec3 &&normal) : Objet(material), orig(orig), normal(glm::normalize(normal)) {}

void from_json(const json &j, Plan &plan) {
	from_json(j, static_cast<Objet &>(plan));
	plan.normal = j.at("normal").get<glm::vec3>();
	plan.orig = j.at("orig").get<glm::vec3>();
}