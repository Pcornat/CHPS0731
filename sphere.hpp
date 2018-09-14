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
	glm::vec3 center;
	int radius;

public:
	Sphere() = default;

	virtual ~Sphere();

	Sphere(float, float, float, int);

	Sphere(float, float, float, int, float, float, float);

	Sphere(float, float, float, int, Material*);

	bool calculIntersection(const Rayon& rayon, const std::vector<Intersection>& I) override;
};


#endif //TP0_SPHERE_HPP
