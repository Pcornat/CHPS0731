//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_PLANS_FACTORY_H
#define RAYTRACER_PLANS_FACTORY_H


#include <DesignPatterns/factory.h>

class PlansFactory : public virtual Factory {
public:
	Objet* createObject(const std::vector<boost::any>& args) override;
};


#endif //RAYTRACER_PLANS_FACTORY_H
