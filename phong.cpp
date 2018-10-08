//
// Created by kevin on 12/09/18.
//

#include "phong.hpp"
#include "scene.h"
#include "rayon.h"

/**
 * Construct a phong material.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(const glm::vec3& ka, const glm::vec3& kd, float ks, float reflection) : ka(ka), kd(kd), ks(ks), reflection(reflection) {}

/**
 * Construct a phong material with r-value.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(glm::vec3&& ka, glm::vec3&& kd, float ks, float reflection) : ka(ka), kd(kd), ks(ks), reflection(reflection) {}

/**
 *
 * @param I
 * @param point
 * @param s
 * @param rayon
 * @param rec
 * @return
 */
glm::vec3 Phong::computeColour(const Intersection& I, const glm::vec3& point, const Scene& s, const Rayon& rayon, int rec) {
	glm::vec3 diff(0, 0, 0), spec(0, 0, 0), R, L;
	for (auto&& light : s.Lights) {
		/*
		 * Diffus = max(N.L, 0) * Kd * Lc
		 * Speculaire= Lc * max(V.R, 0)^Ks
		 * R, V, N, L = direction = vecteur normé
		 */
		L = glm::normalize(light->getPosition() - point), R = glm::normalize(glm::reflect(L, I.getNormal()));
		diff += glm::max(glm::dot(I.getNormal(), L), 0.0f) * this->kd * light->getCouleur();
		spec += light->getCouleur() * glm::pow(glm::max(glm::dot(rayon.Vect(), R), 0.0f), this->ks);
		if (this->reflection != 0.0f) {
			Rayon ray(std::numeric_limits<float>::epsilon() * I.getNormal() + point, glm::reflect(rayon.Vect(), I.getNormal()));
			return this->reflection * ray.Lancer(s, --rec);
		}//*/
	}
	return ka + diff + spec;
}
