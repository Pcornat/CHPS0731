#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <vector>
#include <typeinfo>
#include <glm/glm.hpp>
#include <Interfaces/from_json.h>
#include <intersection.h>
#include <rayon.h>
#include <material.h>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/intersect.hpp>
#include <glm/gtc/noise.hpp>

/**
 * \class Objet
 * This class exists to do polymorphism inside the code.
 */
class Objet : public virtual FromJson {
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
	 * An objet cannot compute its intersection, it is a pure virtual member.
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