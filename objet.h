#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "intersection.h"
#include <vector>
#include "material.h"
#include "glm/glm.hpp"


class Rayon;

class Objet {
protected:
	glm::vec3 color;
	Material* material;

public:

	Objet() = default;

	explicit Objet(const glm::vec3& color) : color(color) {}

	explicit Objet(Material* material) : material(material) {}

	explicit Objet(const glm::vec3& color, Material* material) : color(color), material(material) {}

	virtual bool calculIntersection(Rayon*, std::vector<Intersection>* I) = 0;

	const glm::vec3& getColor() const { return color; }
};


#endif 