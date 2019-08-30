//
// Created by Florent on 04/02/2019.
//

#include "sphere_factory.h"
#include <Materials/phong.h>
#include <typeinfo>

Objet *SphereFactory::createObject(const FromJson::json &object) {
	if (object.at("Material") == "Phong") {

	}
	return nullptr;
}
