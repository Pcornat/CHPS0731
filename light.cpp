#include "light.h"

Light::Light() {

}

Light::~Light() {

}

void Light::setPosition(glm::vec3 p) {
	position = p;
}

void Light::setColor(glm::vec3 c) {
	couleur = c;
}


Light::Light(float x, float y, float z, float r, float g, float b) : position(x, y, z), couleur(r, g, b) {}

const glm::vec3& Light::getPosition() const {
	return position;
}

const glm::vec3& Light::getCouleur() const {
	return couleur;
}
