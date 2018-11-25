#include "scene.h"

void Scene::addObjet(Objet* o) {
	Objets.push_back(o);
}

void Scene::addLight(Light* l) {
	Lights.push_back(l);
}

void Scene::size_to_fit_object() {
	this->Objets.shrink_to_fit();
}

void Scene::size_to_fit_light() {
	this->Lights.shrink_to_fit();
}
