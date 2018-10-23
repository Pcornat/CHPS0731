#include "light.h"

void Light::setPosition(glm::vec3 p) {
	position = p;
}

void Light::setColor(glm::vec3 c) {
	couleur = c;
}


Light::Light(double x, double y, double z, double r, double g, double b) : position(x, y, z), couleur(r, g, b) {}

const glm::vec3& Light::getPosition() const {
	return position;
}

const glm::vec3& Light::getCouleur() const {
	return couleur;
}

Light::Light(const glm::vec3& position, const glm::vec3& couleur) : position(position), couleur(couleur) {}

Light::Light(glm::vec3&& position, glm::vec3&& couleur) : position(position), couleur(couleur) {}
