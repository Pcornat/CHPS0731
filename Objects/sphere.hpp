//
// Created by Florent on 10/09/2018.
//

#ifndef TP0_SPHERE_HPP
#define TP0_SPHERE_HPP

#include "objet.h"

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>
//#include <rayon.h>

/**
 * \class Sphere
 * This class is the representation of a sphere, it's an object by definition too.
 */
class Sphere : public Objet {
private:
	glm::vec3 center;
	int radius;

public:
	Sphere() = default;

	explicit Sphere(const Deserializer::json &json);

	~Sphere() override = default;

	/**
	 *
	 * @param material
	 * @param center
	 * @param radius
	 */
	explicit Sphere(Material *material, const glm::vec3 &center, int radius);

	/**
	 *
	 * @param material
	 * @param center
	 * @param radius
	 */
	explicit Sphere(Material *material, glm::vec3 &&center, int radius);

	/**
 	 * It computes an intersection between a ray and the sphere.
 	 * @param rayon the ray to launch
	 * @param I a pointer to a std::vector of intersection.
	 * @return it computes correctly or not.
	 */
	bool calculIntersection(const Rayon &rayon, const Scene &, std::vector<Intersection> &I, int) override;

};


#endif //TP0_SPHERE_HPP
