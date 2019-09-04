#include "scene.h"

#include <objet.h>
#include <light.h>

void Scene::addObjet(Objet *o) {
	Objets.push_back(o);
}

void Scene::addLight(Light *l) {
	Lights.push_back(l);
}

Scene::~Scene() noexcept {
	for (auto *objet : Objets) {
		delete objet;
	}
	for (auto *light : Lights) {
		delete light;
	}
}