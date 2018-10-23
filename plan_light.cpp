//
// Created by kevin on 23/10/2018.
//

#include "plan_light.h"

Plan_light::Plan_light(glm::highp_dvec3 &&position, glm::highp_dvec3 &&couleur, float height, float width) : Light(
		position, couleur), height(height), width(width) {}

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
