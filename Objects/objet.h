#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "intersection.h"
#include "material.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/intersect.hpp>
#include <glm/gtc/noise.hpp>


class Rayon;

/**
 * \class Objet
 * This class exists to do polymorphism inside the code.
 */
class Objet {
protected:
	Material* material = nullptr;

public:

	Objet() = default;

	virtual ~Objet() = default;

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

	Material* getMaterial() const { return material; }

	void setMaterial(Material* const material) {
		if (this->material != material)
			this->material = material;
	}
};


#endif 