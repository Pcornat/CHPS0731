//
// Created by kevin on 12/09/18.
//

#ifndef CHPS0731_PHONG_H
#define CHPS0731_PHONG_H


#include "material.h"
#include "light.h"

/**
 * \class Phong
 * This class is a material, it defines the texture, the representation of an object.
 * This material is based on the phong model.
 */

class Phong : public Material {
protected:
	///Ambient coeff
	glm::vec3 ka; //(R, G, B)

	///Diff coeff
	glm::vec3 kd; //(R, G, B)

	///Specular coeff
	float ks;

	///Reflection percentage
	float reflection;

public:
	Phong() = default;

	~Phong() override = default;

	explicit Phong(bool refraction, const glm::vec3& ka, const glm::vec3& kd, float ks, float reflection);

	explicit Phong(bool refraction, glm::vec3&& ka, glm::vec3&& kd, float ks, float reflection);

	glm::vec3 computeColour(const Intersection& I, const glm::vec3& point, const Scene& s, const Rayon& rayon, int rec) override;
};


#endif //CHPS0731_PHONG_H
