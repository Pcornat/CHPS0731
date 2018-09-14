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
	glm::vec3 ka; //(R, G, B)
	glm::vec3 kd; //(R, G, B)
	glm::vec3 amb;
	glm::vec3 diff;
	float spec;
	float ks;

public:
	Phong() = default;

	virtual ~Phong();

	Phong(const glm::vec3&, const glm::vec3&, float);

	void Ambiant(const Light& light);

	void Diffuse(const Light& light);

	const glm::vec3& getAmb() const;

	const glm::vec3& getDiff() const;

	float getSpec() const;

};


#endif //CHPS0731_PHONG_H
