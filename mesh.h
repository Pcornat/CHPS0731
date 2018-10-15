//
// Created by Florent on 15/10/2018.
//

#ifndef PROJECT_MESH_H
#define PROJECT_MESH_H


#include "objet.h"
#include "GeometricModel.h"

class Mesh : public Objet {
private:
	GeometricModel model;

public:
	Mesh() = default;

	Mesh(const std::string& name);

	~Mesh() override = default;

	bool calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& vector1, int i) override;
};


#endif //PROJECT_MESH_H
