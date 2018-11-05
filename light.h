#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#include <glm/glm.hpp>
#include "rayon.h"

/**
 * @class Light
 * Light is the base class of any type of light.
 * As for now, it is considered as a point light
 * @todo change this class in a base class for polymorphism.
 */
class Light {
protected:
	///It is the center of the light.
	glm::highp_dvec3 position;
	///Its colour, white almost each time.
	glm::highp_dvec3 couleur;

public:
	Light() = default;

	virtual ~Light() = default;

	explicit Light(const glm::highp_dvec3& position, const glm::highp_dvec3& couleur);

	explicit Light(glm::highp_dvec3&& position, glm::highp_dvec3&& couleur);

	void setPosition(glm::highp_dvec3 p);

	void setColor(glm::highp_dvec3 c);

	const glm::highp_dvec3& getPosition() const;

	const glm::highp_dvec3& getCouleur() const;

	virtual float computeShadow(const glm::vec3& point, const Intersection& I, const Scene& sc, int complexite) = 0;

};

#endif