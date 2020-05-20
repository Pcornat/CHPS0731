#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>
#include <DeSerializer/deserializer.h>

class Rayon;

class Scene;

class Intersection;

/**
 * \class Material
 * Material class, derived only for the different material possible (Phong only at the moment).
 */
class Material {

protected:
	///Refraction or not Refraction ? That is the question :D
	bool refraction{ false };

public:
	Material() = default;

	explicit Material(const json &json);

	explicit Material(bool refraction) : refraction(refraction) {}

	virtual ~Material() = default;

	virtual glm::vec3 computeColour(const Intersection &I, const glm::vec3 &point, const Scene &s, const Rayon &r, int rec) = 0;


};

#endif