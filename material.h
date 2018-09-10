#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include "glm/glm.hpp"
#include "intersection.h"

class Scene;

class Rayon;

class Material {

protected:

public:
	Material() = default;

	virtual glm::vec3 calculColor(const Intersection& I, Scene& s, Rayon* r, int rec) { return glm::vec3(0, 0, 0); };


};

#endif