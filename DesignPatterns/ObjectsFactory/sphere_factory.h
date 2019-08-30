//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_SPHERE_FACTORY_H
#define RAYTRACER_SPHERE_FACTORY_H


#include <DesignPatterns/factory.h>

class SphereFactory : public virtual Factory {
public:
	Objet *createObject(const FromJson::json &object) override;
};


#endif //RAYTRACER_SPHERE_FACTORY_H
