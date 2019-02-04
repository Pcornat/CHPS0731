//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_FACTORY_H
#define RAYTRACER_FACTORY_H


#include <Objects/objet.h>
#include <boost/any.hpp>

class Factory {
public:
	Factory() = default;

	virtual Objet* createObject(const std::vector<boost::any>& args) = 0;//Proto : std::vector<boost::any> ? Quelque chose du genre.

	virtual ~Factory() = default;
};


#endif //RAYTRACER_FACTORY_H
