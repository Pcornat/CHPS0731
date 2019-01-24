#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include <glm/glm.hpp>
#include <memory>
#include "intersection.h"

class Scene;

class Rayon;

/**
 * \class Material
 * Material class, derived only for the different material possible (Phong only at the moment).
 */
class Material : public std::enable_shared_from_this<Material> {

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