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

	explicit Objet(const float r, const float g, const float b) : color(r, g, b) {}

	explicit Objet(Material* material) : material(material) {}

	explicit Objet(const glm::vec3& color, Material* material) : color(color), material(material) {}

	virtual bool calculIntersection(Rayon&, std::vector<Intersection>&) = 0;

	const glm::vec3& getColor() const { return color; }

	Material* getMaterial() const { return material; }
};


#endif 