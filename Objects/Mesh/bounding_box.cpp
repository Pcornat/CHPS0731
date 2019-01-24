//
// Created by Florent on 22/10/2018.
//

#include "bounding_box.h"

BoundingBox::BoundingBox(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax) : minPoint(xMin, yMin, zMin),
																								   maxPoint(xMax, yMax, zMax) {
	box[0] = Plan(nullptr, glm::vec3(0, 0, zMin), glm::vec3(0, 0, -1));
	box[1] = Plan(nullptr, glm::vec3(0, 0, zMax), glm::vec3(0, 0, 1));
	box[2] = Plan(nullptr, glm::vec3(xMin, 0, 0), glm::vec3(-1, 0, 0));
	box[3] = Plan(nullptr, glm::vec3(xMax, 0, 0), glm::vec3(1, 0, 0));
	box[4] = Plan(nullptr, glm::vec3(0, yMin, 0), glm::vec3(0, -1, 0));
	box[5] = Plan(nullptr, glm::vec3(0, yMax, 0), glm::vec3(0, 1, 0));
}

bool BoundingBox::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int complexite) {
	for (auto&& plan : box) {
		if (plan.calculIntersection(rayon, scene, I, complexite)) {
			auto& intersect = I.back();
			glm::vec3 point = rayon.getOrigine() + rayon.vectDirection() * intersect.getDist();
			I.pop_back();
			bool condX = (std::islessequal(point.x, this->maxPoint.x)) && (std::isgreaterequal(point.x, this->minPoint.x)),
					condY = (std::islessequal(point.y, this->maxPoint.y)) && (std::isgreaterequal(point.y, this->minPoint.y)),
					condZ = (std::islessequal(point.z, this->maxPoint.z)) && (std::isgreaterequal(point.z, this->minPoint.z));
			if (condX && condY && condZ) //If point is inside/on the box, then intersection is true.
				return true;
		}
	}
	return false;
}