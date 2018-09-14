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

	virtual ~Material() = 0;

	virtual glm::vec3 computeColour(const Intersection& I, const Scene& s, const Rayon& r, int rec) = 0;


};

#endif