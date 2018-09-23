#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include "intersection.h"
#include <vector>
#include "material.h"
#include <glm/glm.hpp>


class Rayon;

/**
 * \class Objet
 * This class exists to do polymorphism inside the code. It is OOP.
 */
class Objet {
protected:
	glm::vec3 color;
	Material* material = nullptr;

public:

	Objet() = default;

	virtual ~Objet() = default;

	/**
	 * It initializes the colour of the object.
	 * @param r red component
	 * @param g green component
	 * @param b blue component
	 */
	explicit Objet(const float r, const float g, const float b) : color(r, g, b) {}

	/**
	 * It replaces the colour of the object, a material is better.
	 * @param material The material pointer to have.
	 */
	explicit Objet(Material* material) : material(material) {}

	/**
	 * An objet cannot compute its intersection, it is a virtual class.
	 * @return a boolean value : true = intersection, false = no intersection.
	 */
	virtual bool calculIntersection(const Rayon&, const Scene&, std::vector<Intersection>&, int) = 0;

	const glm::vec3& getColor() const { return color; }

	Material* getMaterial() const { return material; }

	void setMaterial(Material* const material) {
		if (this->material != material)
			this->material = material;
	}
};


#endif 