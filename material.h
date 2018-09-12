#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include <glm/glm.hpp>
#include "intersection.h"

class Scene;

class Rayon;

class Material {

protected:

public:
	Material() = default;

	virtual glm::vec3 calculColor(const Intersection& I, Scene& s, Rayon& r, int rec) = 0;


};

#endif