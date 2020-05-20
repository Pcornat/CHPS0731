#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>
#include "DeSerializer/deserializer.h"

class Intersection;

class Scene;

/**
 * @class Light
 * Light is the base class of any type of light.
 */
class Light {
protected:
	///It is the center of the light.
	glm::vec3 position;
	///Its colour, white almost each time.
	glm::vec3 couleur{ 1.f, 1.f, 1.f };

public:
	Light() = default;

	virtual ~Light() = default;

	explicit Light(const glm::vec3 &position, const glm::vec3 &couleur);

	explicit Light(glm::vec3 &&position, glm::vec3 &&couleur);

	void setPosition(const glm::vec3 &p);

	void setColor(const glm::vec3 &c);

	[[nodiscard]] const glm::vec3 &getPosition() const;

	[[nodiscard]] const glm::vec3 &getCouleur() const;

	/**
	 *
	 * @param point
	 * @param I
	 * @param sc
	 * @param complexite
	 * @return
	 */
	[[nodiscard]] virtual float computeShadow(const glm::vec3 &point, const Intersection &I, const Scene &sc, int complexite) const = 0;

	friend void from_json(const json &j, Light &l);
};

#endif