#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include <glm/glm.hpp>
#include "intersection.h"

class Scene;

class Rayon;

class Material {

protected:
	///Refraction or not Refraction ? That is the question :D
	bool refraction;

public:
	Material() = default;

	explicit Material(bool refraction) : refraction(refraction) {}

	virtual ~Material() = default;

	virtual glm::highp_dvec3 computeColour(const Intersection& I, const glm::highp_dvec3& point, const Scene& s, const Rayon& r, int rec) = 0;


};

#endif