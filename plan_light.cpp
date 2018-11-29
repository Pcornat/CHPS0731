//
// Created by kevin on 23/10/2018.
//

#include "plan_light.h"
#include <iostream>
#include <glm/gtx/transform.hpp>

Plan_light::Plan_light(glm::vec3&& position, glm::vec3&& couleur, glm::vec3&& rightDir, glm::vec3&& depthDir, float sampleStep, float height,
					   float width) :
		Light(position, couleur),
		rightDir(rightDir),
		depthDir(depthDir),
		sampleStep(sampleStep),
		height(height),
		width(width) {}

const glm::vec3& Plan_light::getRightDir() const {
	return rightDir;
}

void Plan_light::setRightDir(const glm::vec3& rightDir) {
	Plan_light::rightDir = rightDir;
}

const glm::vec3& Plan_light::getDepthDir() const {
	return depthDir;
}

void Plan_light::setDepthDir(const glm::vec3& depthDir) {
	Plan_light::depthDir = depthDir;
}

float Plan_light::getSampleStep() const {
	return sampleStep;
}

void Plan_light::setSampleStep(float sampleStep) {
	Plan_light::sampleStep = sampleStep;
}

float Plan_light::getHeight() const {
	return height;
}

void Plan_light::setHeight(float height) {
	Plan_light::height = height;
}

float Plan_light::getWidth() const {
	return width;
}

void Plan_light::setWidth(float width) {
	Plan_light::width = width;
}

float Plan_light::computeShadow(const glm::vec3& point, const Intersection& I, const Scene& sc, int complexite) {
	/*
	 * position-----B
	 * 		 |	 	|
	 * 		 | 		|
	 * 		 | 		|
	 * 		 C------D
	 */
	Rayon rayShadow;
	glm::vec3 light = this->position, normal = I.getNormal(), lightDir, pointB, pointC, pointD;
	float offset = 1e-5f,
			numberHeight = this->height / this->sampleStep,
			numberWidth = this->width / this->sampleStep,
			nbTotal = numberHeight * numberWidth;
	float nbOk = 0.f, distance = glm::distance(point, light);
	const glm::mat4 rightDirMat(glm::translate(this->rightDir));
	pointB = rightDirMat * glm::vec4(this->position.x, this->position.y, this->position.z, 1);
	pointC = glm::translate(this->depthDir) * glm::vec4(this->position.x, this->position.y, this->position.z, 1);
	pointD = rightDirMat * glm::vec4(pointC.x, pointC.y, pointC.z, 1);
	rayShadow.Orig(offset * normal + point);
	if (Rayon(rayShadow.Orig(), glm::normalize(this->position - rayShadow.Orig())).shadowRay(sc, distance, complexite - 1)
		&& Rayon(rayShadow.Orig(), glm::normalize(pointB - rayShadow.Orig())).shadowRay(sc, distance, complexite - 1)
		&& Rayon(rayShadow.Orig(), glm::normalize(pointC - rayShadow.Orig())).shadowRay(sc, distance, complexite - 1)
		&& Rayon(rayShadow.Orig(), glm::normalize(pointD - rayShadow.Orig())).shadowRay(sc, distance, complexite - 1)) {
		return 0;
	} else {
		for (std::size_t i = 0; i < numberHeight; ++i) {
			for (std::size_t j = 0; j < numberWidth; ++j) {
				lightDir = glm::normalize(point - light);
				rayShadow.Vect(-lightDir);
				if (rayShadow.shadowRay(sc, glm::distance(point, light), complexite - 1))
					++nbOk;
				light.x += this->sampleStep;
			}
			light.x = this->position.x;
			light.y += this->sampleStep;
		}
	}
	return 1 - (nbOk / nbTotal);
}
