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
Phong::Phong(bool refraction, const glm::vec3 &ka, const glm::vec3 &kd, float ks, float reflection) : Material(refraction),
																									  ka(ka), kd(kd), ks(ks),
																									  reflection(reflection) {}

/**
 * Construct a phong material with r-value.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(bool refraction, glm::vec3 &&ka, glm::vec3 &&kd, float ks, float reflection) : Material(refraction),
																							ka(ka), kd(kd), ks(ks),
																							reflection(reflection) {}

/**
 * Computes colour from the phong model. It also takes care of the reflection.
 * Now, it computes the shadow, soft-shadows to be precise.
 * @todo : tone mapping for the colours (it should be in [0; 1] interval and not in [0; infinity])
 * @param I Inntersection from the ray and the object.
 * @param point The point of the intersection
 * @param s The scene where rays are launched
 * @param rayon The ray that touched the object
 * @param rec The reflection depth
 * @return The object's colour (the normal vector to make it simple)
 */
glm::vec3 Phong::computeColour(const Intersection &I, const glm::vec3 &point, const Scene &s, const Rayon &rayon, int rec) {
	float offset = 1e-4f;
	glm::vec3 amb(0, 0, 0), diff(0, 0, 0), spec(0, 0, 0), R, L, refl(1, 1, 1), min(0, 0, 0), max(1, 1, 1);
	float shad = 0.0f;
	for (auto light : s.getLights()) {
		/*
		 * Diffus = max(N.L, 0) * Kd * Lc
		 * Speculaire= Lc * max(V.R, 0)^Ks
		 * R, V, N, L = direction = vecteur normé
		 */
		L = glm::normalize(point - light->getPosition()), R = glm::normalize(glm::reflect(-L, I.getNormal()));
		//Rayon rayShadow(offset * I.getNormal() + point, -L);

		amb = glm::clamp(amb + this->ka, min, max);
		//diff += glm::max(glm::dot(I.getNormal(), -L), 0.0) * glm::perlin(0.1 * point) * light->getCouleur();
		diff = glm::clamp(diff + glm::max(glm::dot(I.getNormal(), -L), 0.0f) * this->kd * light->getCouleur(),
						  min, max);


		spec = glm::clamp(spec + light->getCouleur() * glm::pow(glm::max(glm::dot(rayon.vectDirection(), R), 0.0f), this->ks),
						  min, max);
		shad += light->computeShadow(point, I, s, rec);
	}
	if (this->reflection != 0.0f)
		if (std::isgreater(refl.x, 1e-4f) || std::isgreater(refl.y, 1e-4f) || std::isgreater(refl.z, 1e-4f)) {
			Rayon reflect(offset * I.getNormal() + point, glm::normalize(glm::reflect(rayon.vectDirection(), I.getNormal())));
			refl = reflect.lancer(s, rec - 1);
		}
	return (1.0f - this->reflection) * shad * (amb + diff + spec) + this->reflection * refl;
}
