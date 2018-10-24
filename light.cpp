#include "light.h"

void Light::setPosition(glm::highp_dvec3 p) {
	position = p;
}

void Light::setColor(glm::highp_dvec3 c) {
	couleur = c;
}


Light::Light(double x, double y, double z, double r, double g, double b) : position(x, y, z), couleur(r, g, b) {}

const glm::highp_dvec3& Light::getPosition() const {
	return position;
}

const glm::highp_dvec3& Light::getCouleur() const {
	return couleur;
}

Light::Light(const glm::highp_dvec3 &position, const glm::highp_dvec3 &couleur, unsigned short type) : position(
		position), couleur(couleur), type(type) {}

Light::Light(glm::highp_dvec3 &&position, glm::highp_dvec3 &&couleur, unsigned short type) : position(position),
																							 couleur(couleur),
																							 type(type) {}

void Light::setType(unsigned short type) {
	Light::type = type;
}

unsigned short Light::getType() const {
	return type;
}


