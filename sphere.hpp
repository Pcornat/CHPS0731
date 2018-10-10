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

	~Sphere() override;

	explicit Sphere(Material* material, const glm::vec3& center, int radius);

	explicit Sphere(Material* material, glm::vec3&& center, int radius);

	bool calculIntersection(const Rayon& rayon, const Scene&, std::vector<Intersection>& I, int) override;
};


#endif //TP0_SPHERE_HPP
