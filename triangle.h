//
// Created by Florent on 04/10/2018.
//

#ifndef PROJECT_TRIANGLE_H
#define PROJECT_TRIANGLE_H


#include "objet.h"
#include "rayon.h"

class Triangle : public Objet {

private:
	glm::highp_dvec3 pointA;
	glm::highp_dvec3 pointB;
	glm::highp_dvec3 pointC;


public:
	Triangle() = default;

	~Triangle() override;

	explicit Triangle(Material* material);

	explicit Triangle(Material* material, const glm::highp_dvec3& pointA, const glm::highp_dvec3& pointB, const glm::highp_dvec3& pointC);

	explicit Triangle(Material* material, glm::highp_dvec3&& pointA, glm::highp_dvec3&& pointB, glm::highp_dvec3&& pointC);

	bool calculIntersection(const Rayon& rayon, const Scene& sc, std::vector<Intersection>& I, int rec) override;
};


#endif //PROJECT_TRIANGLE_H
