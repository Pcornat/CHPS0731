#include "intersection.h"

Intersection::Intersection(float dist, const glm::vec3& normal, Objet* obj) : dist(dist), normal(normal), obj(obj) {}

Intersection::Intersection(float dist, Objet* obj) : dist(dist), obj(obj) {}

Intersection::Intersection(Objet* obj) : obj(obj) {}
