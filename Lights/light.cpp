#include "light.h"

void Light::setPosition(const glm::vec3 &p) {
	position = p;
}

void Light::setColor(const glm::vec3 &c) {
	couleur = c;
}

const glm::vec3 &Light::getPosition() const {
	return position;
}

const glm::vec3 &Light::getCouleur() const {
	return couleur;
}

Light::Light(const glm::vec3 &position, const glm::vec3 &couleur) : position(position), couleur(couleur) {}

Light::Light(glm::vec3 &&position, glm::vec3 &&couleur) : position(position), couleur(couleur) {}

void from_json(const json &j, Light &l) {
	l.position = j.at("position").get<glm::vec3>();
	l.couleur = j.at("couleur").get<glm::vec3>();
}
