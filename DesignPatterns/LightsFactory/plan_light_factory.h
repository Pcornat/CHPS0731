//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_PLAN_LIGHT_FACTORY_H
#define RAYTRACER_PLAN_LIGHT_FACTORY_H


#include <DesignPatterns/factory.h>

class PlanLightFactory : public virtual Factory {
public:
	PlanLightFactory() = default;

	~PlanLightFactory() override = default;

	Objet *createObject(const FromJson::json &object) override;
};


#endif //RAYTRACER_PLAN_LIGHT_FACTORY_H
