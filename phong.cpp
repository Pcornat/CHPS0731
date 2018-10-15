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
Phong::Phong(bool refraction, const glm::highp_dvec3& ka, const glm::highp_dvec3& kd, double ks, double reflection) : Material(refraction), ka(ka),
																													  kd(kd), ks(ks),
																													  reflection(reflection) {}

/**
 * Construct a phong material with r-value.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(bool refraction, glm::highp_dvec3&& ka, glm::highp_dvec3&& kd, double ks, double reflection) : Material(refraction), ka(ka), kd(kd),
																											ks(ks), reflection(reflection) {}

/**
 * Computes colour from the phong model. It also takes care of the reflection.
 * @param I Inntersection from the ray and the object.
 * @param point The point of the intersection
 * @param s The scene where rays are launched
 * @param rayon The ray that touched the object
 * @param rec The reflection depth
 * @return The object's colour (the normal vector to make it simple)
 */
glm::highp_dvec3 Phong::computeColour(const Intersection& I, const glm::highp_dvec3& point, const Scene& s, const Rayon& rayon, int rec) {
    double offset = std::numeric_limits<double>::epsilon() * 1000000;
	glm::highp_dvec3 amb(0, 0, 0), diff(0, 0, 0), spec(0, 0, 0), R, L, refl(0, 0, 0);
	for (auto light : s.Lights) {
		/*
		 * Diffus = max(N.L, 0) * Kd * Lc
		 * Speculaire= Lc * max(V.R, 0)^Ks
		 * R, V, N, L = direction = vecteur normé
		 */
		L = glm::normalize(point - light->getPosition()), R = glm::normalize(glm::reflect(-L, I.getNormal()));
		Rayon rayShadow(offset * I.getNormal() + point, -L);
		amb += this->ka;
		diff += glm::max(glm::dot(I.getNormal(), -L), 0.0) * this->kd * light->getCouleur();
		spec += light->getCouleur() * glm::pow(glm::max(glm::dot(rayon.Vect(), R), 0.0), this->ks);
        if (rayShadow.shadowRay(s, glm::distance(point, light->getPosition()), rec - 1))
            if (this->reflection != 0.0f) {
                Rayon reflect(offset * I.getNormal() + point,
                              glm::normalize(glm::reflect(rayon.Vect(), I.getNormal())));
                refl = reflect.Lancer(s, rec - 1);
                return (1.0 - this->reflection) * (0.5 * (this->reflection * amb + diff + spec)) +
                       this->reflection * refl;
			} else {
				return 0.5 * (amb + diff + spec);
			}
	}
	if (this->reflection != 0.0f) {
		Rayon reflect(offset * I.getNormal() + point, glm::normalize(glm::reflect(rayon.Vect(), I.getNormal())));
		refl = reflect.Lancer(s, rec - 1);
		return (1.0 - this->reflection) * (this->reflection * amb + diff + spec) + this->reflection * refl;
	} else
		return amb + diff + spec;
}
