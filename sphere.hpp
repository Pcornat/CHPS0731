//
// Created by Florent on 10/09/2018.
//

#ifndef TP0_SPHERE_HPP
#define TP0_SPHERE_HPP


#include "objet.h"

/**
 * \class Sphere
 * This class is the representation of a sphere, it's an object by definition too.
 */
class Sphere : public Objet {
private:
	glm::vec3 origin;
	int radius;

public:
	/**
	 * Giving position of the sphere and its "rayon" (fuck english)
	 */
	Sphere(float, float, float, int);

	/**
	 * Giving position of the sphere and its color
	 */
	Sphere(float, float, float, int, const glm::vec3&);

	/**
	 * It computes an intersection between a ray and the sphere.
	 * @param rayon the ray to launch
	 * @param I a pointer to a vector of intersection.
	 * @return it computes correctly or not.
	 */
	bool calculIntersection(Rayon* rayon, std::vector<Intersection>* I) override;
};


#endif //TP0_SPHERE_HPP
