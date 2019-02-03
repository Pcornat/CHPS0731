//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"


bool Sphere::calculIntersection(const Rayon& rayon, const Scene& sc, std::vector<Intersection>& I, int rec) {
	//Équation : a = 1, b = 2* (D.(O - C)), c =|O - C|² - R²
	/*glm::vec3 OCVec = rayon.setOrigine() - this->center;
	double a = 1,
			b = 2 * glm::dot(rayon.setVectDirection(), OCVec),
			c = glm::dot(OCVec, OCVec) - this->radius * this->radius, delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return false;
	if (delta == 0) {
		double dist = -0.5f * b / a;
		glm::vec3 point = rayon.setOrigine() + (rayon.setVectDirection() * dist), norm = (point - this->center) / glm::length(point - this->center);
		Intersection intersection(dist, norm, this);
		intersection.setNormal(this->material->computeColour(intersection, point, sc, rayon, rec));
		I.push_back(intersection);
		return true;
	}
	double q = (b > 0) ? -0.5f * (b + sqrtf(delta)) : -0.5f * (b - sqrtf(delta)),
			x0 = q / a,
			x1 = c / q;
	if (x0 > x1) std::swap(x0, x1);
	glm::vec3 point = rayon.getOrigine() + (rayon.vectDirection() * x0), norm = (point - this->center) / glm::length(point - this->center);
	Intersection intersection(x0, norm, this);
	intersection.setNormal(this->material->computeColour(intersection, point, sc, rayon, rec));
	I.push_back(intersection);*/
	float dist = 0.0f;
	if (!glm::intersectRaySphere(rayon.getOrigine(), rayon.vectDirection(), this->center, this->radius, dist)) {
		return false;
	}
	glm::vec3 point = rayon.getOrigine() + (rayon.vectDirection() * dist), norm = glm::normalize(
			(point - this->center) / glm::length(point - this->center));
	I.emplace_back(dist, norm, this);
	return true;
}

Sphere::~Sphere() {
	delete material;
}

Sphere::Sphere(Material* material, glm::vec3&& center, int radius) : Objet(material), center(center), radius(radius) {}

Sphere::Sphere(Material* material, const glm::vec3& center, int radius) : Objet(material), center(center),
																		  radius(radius) {}

void Sphere::fromJson(const FromJson::json& objet) const {

}