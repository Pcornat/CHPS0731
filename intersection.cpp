#include "intersection.h"

Intersection::Intersection(double dist, const glm::highp_dvec3& normal, Objet* obj) : dist(dist), normal(normal), obj(obj) {}

Intersection::Intersection(double dist, Objet* obj) : dist(dist), obj(obj) {}

Intersection::Intersection(Objet* obj) : obj(obj) {}

const glm::highp_dvec3& Intersection::getNormal() const {
	return normal;
}

void Intersection::setNormal(const glm::highp_dvec3& normal) {
	Intersection::normal = normal;
}

double Intersection::getDist() const {
	return dist;
}

Objet* Intersection::getObj() const {
	return obj;
}
