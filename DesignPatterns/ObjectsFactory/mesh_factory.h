//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_MESH_FACTORY_H
#define RAYTRACER_MESH_FACTORY_H


#include <DesignPatterns/factory.h>

class MeshFactory : public virtual Factory {
public:
	Objet* createObject(const std::vector<boost::any>& args) override;
};


#endif //RAYTRACER_MESH_FACTORY_H
