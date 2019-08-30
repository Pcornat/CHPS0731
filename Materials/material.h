#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include <glm/glm.hpp>
#include <scene.h>
#include <rayon.h>
#include <intersection.h>

/**
 * \class Material
 * Material class, derived only for the different material possible (Phong only at the moment).
 */
class Material {

protected:
	///Refraction or not Refraction ? That is the question :D
	bool refraction;

public:
	Material() = default;

	explicit Material(bool refraction) : refraction(refraction) {}

	virtual ~Material() = default;

	virtual glm::vec3 computeColour(const Intersection& I, const glm::vec3& point, const Scene& s, const Rayon& r, int rec) = 0;


};

#endif