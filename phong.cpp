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
 * Computes colour from the phong model. It also takes care of the reflection.
 * @param I Inntersection from the ray and the object.
 * @param point The point of the intersection
 * @param s The scene where rays are launched
 * @param rayon The ray that touched the object
 * @param rec The reflection depth
 * @return The object's colour (the normal vector to make it simple)
 */
glm::vec3 Phong::computeColour(const Intersection& I, const glm::vec3& point, const Scene& s, const Rayon& rayon, int rec) {
	glm::vec3 diff(0, 0, 0), spec(0, 0, 0), R, L, refl(0, 0, 0);
	for (Light* light : s.Lights) {
		/*
		 * Diffus = max(N.L, 0) * Kd * Lc
		 * Speculaire= Lc * max(V.R, 0)^Ks
		 * R, V, N, L = direction = vecteur normé
		 */
		L = light->getPosition() - point;
		R = glm::normalize(glm::reflect(L, I.getNormal()));
		Rayon rayShadow(point, L);
		if (rayShadow.shadowRay(s, glm::abs(glm::distance(light->getPosition(), point))))
			return this->ka;
		diff += glm::max(glm::dot(I.getNormal(), L), 0.0f) * this->kd * light->getCouleur();
		spec += light->getCouleur() * glm::pow(glm::max(glm::dot(rayon.Vect(), R), 0.0f), this->ks);
		if (this->reflection != 0.0f) {
			Rayon ray(1e-4f * I.getNormal() + point, glm::reflect(-rayon.Vect(), I.getNormal()));
			refl += ray.Lancer(s, --rec);
		}//*/
	}
	if (this->reflection != 0.0f)
		//return (1-this->reflection) * (this->ka + diff + spec) + this->reflection * refl;
		return this->reflection * (ka + diff + spec + refl);
	return this->reflection * ka + diff + spec;
}
