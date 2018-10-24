//
// Created by kevin on 23/10/2018.
//

#include "plan_light.h"

Plan_light::Plan_light(glm::highp_dvec3 &&position, glm::highp_dvec3 &&couleur, float height, float width,
					   float sampleStep, unsigned short type) : Light(
		position, couleur, type), height(height), width(width), sampleStep(sampleStep) {}

Plan_light::~Plan_light() {

}

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

unsigned short Plan_light::getType() const {
	return type;
}

void Plan_light::setType(unsigned short type) {
	Plan_light::type = type;
}
