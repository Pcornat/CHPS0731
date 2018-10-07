//
// Created by Florent on 04/10/2018.
//

#include "triangle.h"


Triangle::Triangle(Material* material) : Objet(material) {

}

Triangle::Triangle(const glm::vec3& color) : Objet(color) {

}

Triangle::Triangle(glm::vec3&& color) : Objet(color) {

}

/**
 *
 * @param rayon
 * @param sc
 * @param I
 * @param rec
 * @return
 */
bool Triangle::calculIntersection(const Rayon& rayon, const Scene& sc, std::vector<Intersection>& I, int rec) {
	float dist = 0.10f;
	glm::vec2 baryCentre;
	if (glm::intersectRayTriangle(rayon.Orig(), rayon.Vect(), this->pointA, this->pointB, this->pointC, baryCentre, dist)) {
		I.emplace_back(dist, this->color, this);
		return true;
	}
	return false;
}

Triangle::Triangle(Material* material, const glm::vec3& pointA, const glm::vec3& pointB, const glm::vec3& pointC)
		: Objet(material), pointA(pointA), pointB(pointB), pointC(pointC) {}

Triangle::Triangle(const glm::vec3& color, const glm::vec3& pointA, const glm::vec3& pointB, const glm::vec3& pointC)
		: Objet(color), pointA(pointA), pointB(pointB), pointC(pointC) {}

Triangle::Triangle(glm::vec3&& color, const glm::vec3& pointA, const glm::vec3& pointB, const glm::vec3& pointC)
		: Objet(color), pointA(pointA), pointB(pointB), pointC(pointC) {}

Triangle::~Triangle() {
	delete this->material;
}
