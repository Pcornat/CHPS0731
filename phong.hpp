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
private:
	///Ambient coeff
	glm::highp_dvec3 ka; //(R, G, B)

	///Diff coeff
	glm::highp_dvec3 kd; //(R, G, B)

	///Specular coeff
	double ks;

	///Reflection percentage
	double reflection;

public:
	Phong() = default;

	~Phong() override = default;

	explicit Phong(bool, const glm::highp_dvec3&, const glm::highp_dvec3&, double, double);

	explicit Phong(bool, glm::highp_dvec3&&, glm::highp_dvec3&&, double, double);

	glm::highp_dvec3 computeColour(const Intersection& I, const glm::highp_dvec3& point, const Scene& s, const Rayon& rayon, int rec) override;
};


#endif //CHPS0731_PHONG_H
