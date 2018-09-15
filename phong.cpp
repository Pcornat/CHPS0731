//
// Created by kevin on 12/09/18.
//

#include "phong.h"

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

void Phong::Ambiant(const Light& light) {

}

void Phong::Diffuse(const Light& light) {

}

const glm::vec3& Phong::getAmb() const {
	return amb;
}

const glm::vec3& Phong::getDiff() const {
	return diff;
}

float Phong::getSpec() const {
	return spec;
}

glm::vec3 Phong::computeColour(const Intersection& I, const Scene& s, const Rayon& r, int rec) {
	return glm::vec3();
}
