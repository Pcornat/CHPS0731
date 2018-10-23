//
// Created by Florent on 04/10/2018.
//

#include "triangle.h"


Triangle::Triangle(Material* material) : Objet(material) {

}

/**
 * Compute the intersection between a ray and a triangle object.
 * @param rayon The ray that is shot at the triangle.
 * @param sc The scene where rays are shot.
 * @param I The intersection vector where all intersection are stored.
 * @param rec The reflection depth.
 * @return True : intersection, false : no intersection.
 */
bool Triangle::calculIntersection(const Rayon& rayon, const Scene& sc, std::vector<Intersection>& I, int rec) {
	double dist = 0;
	glm::highp_dvec2 baryCentre;
	if (!glm::intersectRayTriangle(rayon.Orig(), rayon.Vect(), this->pointA, this->pointB, this->pointC, baryCentre, dist)) {
		return false;
	}
	glm::highp_dvec3 norm = glm::cross(this->pointA - this->pointB, this->pointA - this->pointC);
	I.emplace_back(dist, norm, this);
	return true;
}

Triangle::Triangle(Material* material, const glm::highp_dvec3& pointA, const glm::highp_dvec3& pointB, const glm::highp_dvec3& pointC)
		: Objet(material), pointA(pointA), pointB(pointB), pointC(pointC) {}

Triangle::~Triangle() {
	delete this->material;
}

Triangle::Triangle(Material* material, glm::highp_dvec3&& pointA, glm::highp_dvec3&& pointB, glm::highp_dvec3&& pointC) : Objet(material),
																														  pointA(pointA),
																														  pointB(pointB),
																														  pointC(pointC) {}
