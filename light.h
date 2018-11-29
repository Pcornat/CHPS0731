#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#include "rayon.h"

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>

/**
 * @class Light
 * Light is the base class of any type of light.
 * As for now, it is considered as a point light
 * @todo change this class in a base class for polymorphism.
 */
class Light {
protected:
	///It is the center of the light.
	glm::vec3 position;
	///Its colour, white almost each time.
	glm::vec3 couleur;

public:
	Light() = default;

	virtual ~Light() = default;

	explicit Light(const glm::vec3& position, const glm::vec3& couleur);

	explicit Light(glm::vec3&& position, glm::vec3&& couleur);

	void setPosition(glm::vec3 p);

	void setColor(glm::vec3 c);

	const glm::vec3& getPosition() const;

	const glm::vec3& getCouleur() const;

	virtual float computeShadow(const glm::vec3& point, const Intersection& I, const Scene& sc, int complexite) = 0;

};

#endif