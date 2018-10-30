#include "light.h"

void Light::setPosition(glm::vec3 p) {
	position = p;
}

void Light::setColor(glm::vec3 c) {
	couleur = c;
}


const glm::vec3& Light::getPosition() const {
	return position;
}

const glm::vec3& Light::getCouleur() const {
	return couleur;
}

void Light::setType(unsigned short type) {
	Light::type = type;
}

unsigned short Light::getType() const {
	return Light::type;
}

Light::Light(const glm::vec3& position, const glm::vec3& couleur, unsigned short type) : position(position), couleur(couleur), type(type) {}

Light::Light(glm::vec3&& position, glm::vec3&& couleur, unsigned short type) : position(position), couleur(couleur), type(type) {}
