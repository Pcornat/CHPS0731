//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"
#include "rayon.h"
#include "phong.hpp"


/**
 * It computes an intersection between a ray and the sphere.
 * @param rayon the ray to launch
 * @param I a pointer to a std::vector of intersection.
 * @return it computes correctly or not.
 */
bool Sphere::calculIntersection(const Rayon& rayon, const Scene& sc, std::vector<Intersection>& I, int rec) {
	//Équation : a = 1, b = 2* (D.(O - C)), c =|O - C|² - R²
	/*glm::vec3 OCVec = rayon.Orig() - this->center;
	float a = 1,
			b = 2 * glm::dot(rayon.Vect(), OCVec),
			c = glm::dot(OCVec, OCVec) - this->radius * this->radius, delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return false;
	if (delta == 0) {
		float dist = -0.5f * b / a;
		glm::vec3 point = rayon.Orig() + (rayon.Vect() * dist), norm = (point - this->center) / glm::length(point - this->center);
		Intersection intersection(dist, norm, this);
		intersection.setNormal(this->material->computeColour(intersection, point, sc, rayon, rec));
		I.push_back(intersection);
		return true;
	}
	float q = (b > 0) ? -0.5f * (b + sqrtf(delta)) : -0.5f * (b - sqrtf(delta)),
			x0 = q / a,
			x1 = c / q;
	if (x0 > x1) std::swap(x0, x1);
	glm::vec3 point = rayon.Orig() + (rayon.Vect() * x0), norm = (point - this->center) / glm::length(point - this->center);
	Intersection intersection(x0, norm, this);
	intersection.setNormal(this->material->computeColour(intersection, point, sc, rayon, rec));
	I.push_back(intersection);*/
	float dist = 0.0f;
	if (!glm::intersectRaySphere(rayon.Orig(), rayon.Vect(), this->center, this->radius, dist)) {
		return false;
	}
	glm::vec3 point = rayon.Orig() + (rayon.Vect() * dist), norm =
			(point - this->center) / glm::length(point - this->center);
	Intersection intersection(dist, norm, this);
	if (this->material != nullptr)
		intersection.setNormal(this->material->computeColour(intersection, point, sc, rayon, rec));
	else
		intersection.setNormal(this->color);
	I.push_back(intersection);
	return true;
}

/**
 * Constructor without colour
 * @param x coordinate of the center.
 * @param y coordinate of the center.
 * @param z coordinate of the center.
 * @param r Radius of the sphere.
 */
Sphere::Sphere(const float x, const float y, const float z, const int r) : center(x, y, z), radius(r) {}

/**
 * Colour is added
 * @param r Red
 * @param g Green
 * @param b Blue
 * @sa Sphere(float, float, float, r)
 */
Sphere::Sphere(const float x, const float y, const float z, const int radius, const float r, const float g,
			   const float b) : Objet(r, g, b),
								center(x, y, z),
								radius(radius) {}

/**
 * It constructs the sphere with a material.
 * @param x coordinate of the center.
 * @param y coordinate of the center.
 * @param z coordinate of the center.
 * @param r radius of the sphere.
 * @param material The material of the sphere.
 */
Sphere::Sphere(const float x, const float y, const float z, const int r, Material* const material) : Objet(material),
																									 center(x, y, z),
																									 radius(r) {}

Sphere::~Sphere() {
	delete material;
}

Sphere::Sphere(glm::vec3&& color, glm::vec3&& center, int radius) : Objet(color), center(center), radius(radius) {}

Sphere::Sphere(const glm::vec3& color, const glm::vec3& center, int radius) : Objet(color), center(center),
																			  radius(radius) {}

Sphere::Sphere(Material* material, glm::vec3&& center, int radius) : Objet(material), center(center), radius(radius) {}

Sphere::Sphere(Material* material, const glm::vec3& center, int radius) : Objet(material), center(center),
																		  radius(radius) {}
