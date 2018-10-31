#include "light.h"

void Light::setPosition(glm::highp_dvec3 p) {
	position = p;
}

void Light::setColor(glm::highp_dvec3 c) {
	couleur = c;
}

const glm::highp_dvec3& Light::getPosition() const {
	return position;
}

const glm::highp_dvec3& Light::getCouleur() const {
	return couleur;
}

Light::Light(const glm::highp_dvec3& position, const glm::highp_dvec3& couleur) : position(position), couleur(couleur) {}

Light::Light(glm::highp_dvec3&& position, glm::highp_dvec3&& couleur) : position(position), couleur(couleur) {}