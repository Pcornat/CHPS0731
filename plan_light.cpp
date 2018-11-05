//
// Created by kevin on 23/10/2018.
//

#include <iostream>
#include "plan_light.h"

Plan_light::Plan_light(glm::vec3&& position, glm::vec3&& couleur, float height, float width, float sampleStep) : Light(
		position, couleur), height(height), width(width), sampleStep(sampleStep) {}

void Plan_light::setHeight(float height) {
	Plan_light::height = height;
}

void Plan_light::setWidth(float width) {
	Plan_light::width = width;
}

float Plan_light::getHeight() const {
	return height;
}

float Plan_light::getWidth() const {
	return width;
}

float Plan_light::getSampleStep() const {
	return sampleStep;
}

void Plan_light::setSampleStep(float sampleStep) {
	Plan_light::sampleStep = sampleStep;
}

float Plan_light::computeShadow(const glm::vec3& point, const Intersection& I, const Scene& sc, int complexite) {
	Rayon rayShadow;
	glm::vec3 light = this->position, normal = I.getNormal(), lightDir;
	float offset = std::numeric_limits<float>::epsilon() * 100,
			numberHeight = this->height / this->sampleStep,
			numberWidth = this->width / this->sampleStep,
			nbTotal = numberHeight * numberWidth;
	float nbOk = 0.f;
	rayShadow.Orig(offset * normal + point);
	for (std::size_t i = 0; i < numberHeight; ++i) {
		for (std::size_t j = 0; j < numberWidth; ++j) {
			lightDir = glm::normalize(point - light);
			rayShadow.Vect(-lightDir);
			if (rayShadow.shadowRay(sc, glm::distance(point, light), complexite - 1))
				++nbOk;
			light.x += this->sampleStep;
		}
		light.x = static_cast<float>(this->position.x);
		light.y += this->sampleStep;
	}
	return 1 - (nbOk / nbTotal);
}
