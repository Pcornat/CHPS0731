#include "scene.h"

#include <Objects/objet.h>
#include <Lights/light.h>

void Scene::addObjet(Objet *o) {
	objets.emplace_back(o);
}

void Scene::addLight(Light *l) {
	lights.emplace_back(l);
}