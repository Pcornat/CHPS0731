//
// Created by Florent on 23/10/2018.
//

#ifndef PROJECT_TEXTURE_H
#define PROJECT_TEXTURE_H


#include "material.h"

class Texture : public Material {
public:
	Texture() = default;

	explicit Texture(const json &json);

	explicit Texture(bool refraction);

	~Texture() override = default;

	glm::vec3 computeColour(const Intersection &I, const glm::vec3 &point, const Scene &s, const Rayon &r, int rec) override;
};


#endif //PROJECT_TEXTURE_H
