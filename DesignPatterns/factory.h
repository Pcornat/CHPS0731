//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_FACTORY_H
#define RAYTRACER_FACTORY_H


#include <Objects/objet.h>
#include <from_json.h>

class Factory {
public:
	Factory() = default;

	/**
	 * Pure virtual member used to create an object from its JSON representation.
	 * @param object
	 * @return
	 */
	virtual Objet *createObject(const FromJson::json &object) = 0;//Construction à partir du json correspondant à l'objet.

	virtual ~Factory() = default;
};


#endif //RAYTRACER_FACTORY_H
