//
// Created by Florent on 28/11/2018.
//

#include "perlin.h"
#include <glm/gtc/noise.hpp>

glm::vec3 Perlin::computeColour(const Intersection& I, const glm::vec3& point, const Scene& s, const Rayon& rayon, int rec) {
	float offset = 1e-4f;
	glm::vec3 amb(0, 0, 0), diff(0, 0, 0), spec(0, 0, 0), R, L, refl(1, 1, 1), min(0, 0, 0), max(1, 1, 1);
	float shad = 0.0f;
	for (auto light : s.Lights) {
		/*
		 * Diffus = max(N.L, 0) * Kd * Lc
		 * Speculaire= Lc * max(V.R, 0)^Ks
		 * R, V, N, L = direction = vecteur normé
		 */
		L = glm::normalize(point - light->getPosition()), R = glm::normalize(glm::reflect(-L, I.getNormal()));

		amb = glm::clamp(amb + this->ka, min, max);

		diff += glm::max(glm::dot(I.getNormal(), -L), 0.0f) * glm::perlin(0.1f * point) * light->getCouleur();


		spec = glm::clamp(spec + light->getCouleur() * glm::pow(glm::max(glm::dot(rayon.Vect(), R), 0.0f), this->ks),
						  min, max);
		shad += light->computeShadow(point, I, s, rec);
	}
	if (this->reflection != 0.0f)
		if (std::isgreater(refl.x, 1e-4f) || std::isgreater(refl.y, 1e-4f) || std::isgreater(refl.z, 1e-4f)) {
			Rayon reflect(offset * I.getNormal() + point, glm::normalize(glm::reflect(rayon.Vect(), I.getNormal())));
			refl = reflect.Lancer(s, rec - 1);
		}
	return (1.0f - this->reflection) * shad * (amb + diff + spec) + this->reflection * refl;
}

Perlin::Perlin(bool refraction, const glm::vec3& ka, const glm::vec3& kd, float ks, float reflection, float coeff) :
		Phong(refraction, ka, kd, ks, reflection), coeff(coeff) {}

Perlin::Perlin(bool refraction, glm::vec3&& ka, glm::vec3&& kd, float ks, float reflection, float coeff) :
		Phong(refraction, ka, kd, ks, reflection), coeff(coeff) {}