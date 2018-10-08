//
// Created by postaron on 22/09/18.
//

#include "plan.hpp"
#include "phong.hpp"

/**
 * @param rayon
 * @param scene
 * @param I
 * @param rec
 */
bool Plan::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int rec) {
	/*float denom = glm::dot(this->normal, rayon.Vect());
	if (glm::abs(denom) > std::numeric_limits<float>::epsilon()) {
		glm::vec3 vecDistOrigPlan = this->orig - rayon.Orig();
		float dist = glm::dot(vecDistOrigPlan, this->normal) / denom;
		I.emplace_back(dist, this->color, this);
		return (dist >= 0);
	}
	return false;//*/
	float dist = 0.0f;
	if (!glm::intersectRayPlane(rayon.Orig(), rayon.Vect(), this->orig, this->normal, dist)) {
		return false;
	}
	glm::vec3 point = rayon.Orig() + (rayon.Vect() * dist);
	Intersection intersection(dist, this->normal, this);
	if (this->material != nullptr)
		intersection.setNormal(this->material->computeColour(intersection, point, scene, rayon, rec));
	else
		intersection.setNormal(this->color);
	I.push_back(intersection);
	return true;//*/
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

Plan::Plan(const glm::vec3& color, const glm::vec3& orig, const glm::vec3& normal) : Objet(color), orig(orig), normal(glm::normalize(normal)) {}

Plan::Plan(glm::vec3&& color, glm::vec3&& orig, glm::vec3&& normal) : Objet(color), orig(orig), normal(glm::normalize(normal)) {}

Plan::Plan(Material* material, const glm::vec3& orig, const glm::vec3& normal) : Objet(material), orig(orig), normal(normal) {}

Plan::Plan(Material* material, glm::vec3&& orig, glm::vec3&& normal) : Objet(material), orig(orig), normal(normal) {}
