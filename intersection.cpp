#include "intersection.h"

Intersection::Intersection(float dist, const glm::vec3& normal, Objet* obj) : dist(dist), normal(normal), obj(obj) {}

Intersection::Intersection(float dist, Objet* obj) : dist(dist), obj(obj) {}

Intersection::Intersection(Objet* obj) : obj(obj) {}

const glm::vec3& Intersection::getNormal() const {
	return normal;
}

void Intersection::setNormal(const glm::vec3& normal) {
	Intersection::normal = normal;
}

float Intersection::getDist() const {
	return dist;
}

Objet* Intersection::getObj() const {
	return obj;
}

void Intersection::setObj(Objet* obj) {
	Intersection::obj = obj;
}
