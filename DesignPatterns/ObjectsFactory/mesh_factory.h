//
// Created by Florent on 04/02/2019.
//

#ifndef RAYTRACER_MESH_FACTORY_H
#define RAYTRACER_MESH_FACTORY_H


#include <DesignPatterns/factory.h>

class MeshFactory : public virtual Factory {
public:
	MeshFactory() = default;

	~MeshFactory() override = default;

	Objet *createObject(const FromJson::json &object) override;
};


#endif //RAYTRACER_MESH_FACTORY_H
