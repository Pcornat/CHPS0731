//
// Created by kevin on 12/09/18.
//

#include <glm/gtc/noise.hpp>
#include "phong.hpp"

/**
 * Construct a phong material.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(bool refraction, const glm::highp_dvec3& ka, const glm::highp_dvec3& kd, double ks, double reflection)
		: Material(refraction), ka(ka),
		  kd(kd), ks(ks),
		  reflection(reflection) {}

/**
 * Construct a phong material with r-value.
 * @param ka Ambient coef
 * @param kd Diffusion coef
 * @param ks Specular coef
 */
Phong::Phong(bool refraction, glm::highp_dvec3&& ka, glm::highp_dvec3&& kd, double ks, double reflection) : Material(
		refraction), ka(ka), kd(kd),
																											ks(ks),
																											reflection(
																													reflection) {}

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
glm::highp_dvec3 Phong::computeColour(const Intersection& I, const glm::highp_dvec3& point, const Scene& s, const Rayon& rayon, int rec) {
	double offset = std::numeric_limits<double>::epsilon() * 1000000;
	glm::highp_dvec3 amb(0, 0, 0), diff(0, 0, 0), spec(0, 0, 0), R, L, Li, Ld, Ltmp, refl(0, 0, 0), min(0, 0, 0), max(1, 1, 1);
	float nbOk = 0.f, nbTotal = 0.f;
	double shad = 1.f;
	for (auto light : s.Lights) {
		/*
		 * Diffus = max(N.L, 0) * Kd * Lc
		 * Speculaire= Lc * max(V.R, 0)^Ks
		 * R, V, N, L = direction = vecteur normé
		 */


		L = glm::normalize(point - light->getPosition()), R = glm::normalize(glm::reflect(-L, I.getNormal()));
		Rayon rayShadow(offset * I.getNormal() + point, -L);

		amb = glm::clamp(amb + this->ka, min, max);
		/*diff += glm::max(glm::dot(I.getNormal(), -L), 0.0) * glm::perlin(0.1 * point) * light->getCouleur();*/
		diff = glm::clamp(diff + glm::max(glm::dot(I.getNormal(), -L), 0.0) * this->kd * light->getCouleur(),
						  min, max);


		spec = glm::clamp(spec + light->getCouleur() * glm::pow(glm::max(glm::dot(rayon.Vect(), R), 0.0), this->ks),
						  min, max);
		shad = light->computeShadow(point, I, s, rec);
		/*Li = light->getPosition();
		Ltmp = Li;
		Ld = glm::normalize(point - Li);
		if (rayShadow.shadowRay(s, glm::distance(point, Li), rec - 1)) {
			for (int i = 0; i < light->getWidth() / light->getSampleStep(); i++) {
				Li.x += light->getSampleStep();
				Li.y = Ltmp.y;
				for (int j = 0; j < light->getHeight() / light->getSampleStep(); j++) {
					Li.y += light->getSampleStep();
					Ld = glm::normalize(point - Li);
					Rayon rayon1(offset * I.getNormal() + point, -Ld);
					if (rayon1.shadowRay(s, glm::distance(point, Li), rec - 1)) {
						nbOk++;
					}
				}
			}
			nbTotal = ((light->getWidth() * light->getHeight()) / light->getSampleStep());
			shad = nbOk / nbTotal;
		}*/
		if (shad == 0)
			shad = 1;
		if (this->reflection != 0.0f) {
			Rayon reflect(offset * I.getNormal() + point, glm::normalize(glm::reflect(rayon.Vect(), I.getNormal())));
			refl = reflect.Lancer(s, rec - 1);
			return (1.0 - this->reflection) * shad * (amb + diff + spec) + this->reflection * refl;
		} else
			return shad * (amb + diff + spec);
	}
}
