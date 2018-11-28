//
// Created by kevin on 23/10/2018.
//

#include <iostream>
#include "plan_light.h"

Plan_light::Plan_light(glm::vec3&& position, glm::vec3&& couleur, glm::vec3&& height, glm::vec3&& width, float sampleStep) : Light(
		position, couleur), height(height), width(width), sampleStep(sampleStep) {}

const glm::vec3& Plan_light::getHeight() const {
	return height;
}

void Plan_light::setHeight(const glm::vec3& height) {
	Plan_light::height = height;
}

const glm::vec3& Plan_light::getWidth() const {
	return width;
}

void Plan_light::setWidth(const glm::vec3& width) {
	Plan_light::width = width;
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
	float offset = 1e-5f,
			numberHeight = glm::abs(glm::length(this->position - this->height)) / this->sampleStep,
			numberWidth = glm::abs(glm::length(this->position - this->width)) / this->sampleStep,
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
