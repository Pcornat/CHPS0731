#include "intersection.h"
#include "Objects/objet.h"

Intersection::Intersection(float dist, const glm::vec3 &normal, const Objet *obj) : dist(dist), normal(normal), obj(obj) {}

Intersection::Intersection(float dist, const Objet *obj) : dist(dist), obj(obj) {}

Intersection::Intersection(const Objet *obj) : obj(obj) {}

const glm::vec3 &Intersection::getNormal() const {
	return normal;
}

void Intersection::setNormal(const glm::vec3 &normal) {
	Intersection::normal = normal;
}

float Intersection::getDist() const {
	return dist;
}

const Objet *Intersection::getObj() const {
	return obj;
}

