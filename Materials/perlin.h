//
// Created by Florent on 28/11/2018.
//

#ifndef PROJECT_PERLIN_H
#define PROJECT_PERLIN_H


#include "phong.h"

class Perlin : public Phong {
private:
	float coeff;
public:

	Perlin() = default;

	explicit Perlin(const Deserializer::json &json);

	~Perlin() override = default;

	explicit Perlin(bool refraction, const glm::vec3 &ka, const glm::vec3 &kd, float ks, float reflection, float coeff);

	explicit Perlin(bool refraction, glm::vec3 &&ka, glm::vec3 &&kd, float ks, float reflection, float coeff);

	glm::vec3 computeColour(const Intersection &I, const glm::vec3 &point, const Scene &s, const Rayon &rayon, int rec) override;
};


#endif //PROJECT_PERLIN_H
