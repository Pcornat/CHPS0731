//
// Created by kevin on 12/09/18.
//

#include "phong.h"
#include "scene.h"
#include "rayon.h"

/**
 * Construct a phong material.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(const glm::vec3& ka, const glm::vec3& kd, float ks) : ka(ka), kd(kd), ks(ks) {}

/**
 * Construct a phong material with r-value.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(glm::vec3&& ka, glm::vec3&& kd, float ks) : ka(ka), kd(kd), ks(ks) {}

/**
 * To compute the ambient.
 * @param light The light to use
 */
void Phong::Ambiant(const Light& light) {

}

/**
 * To compute the diffuse vector.
 * @param light Light to use.
 */
void Phong::Diffuse(const Light& light) {

}

const glm::vec3& Phong::getAmb() const {
	return ka;
}

const glm::vec3& Phong::getDiff() const {
	return diff;
}

const glm::vec3& Phong::getSpec() const {
	return spec;
}

glm::vec3 Phong::computeColour(const Intersection& I, const Scene& s, const Rayon& r, int rec) {
	for (auto&& light : s.Lights) {
		auto temp = glm::max(glm::dot(I.normal, glm::normalize(light->getPosition())), 0.0f);
		this->diff = temp * this->kd * light->getCouleur();
		this->spec = glm::pow(glm::max(glm::dot(r.Vect(), glm::normalize(glm::reflect(r.Vect(), I.normal))), 0.0f),
							  this->ks) *
					 light->getCouleur();

	}
	return ka + diff + spec;
}
