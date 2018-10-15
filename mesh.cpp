//
// Created by Florent on 15/10/2018.
//

#include "mesh.h"

bool Mesh::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& vector1, int i) {
	return false;
}

Mesh::Mesh(const std::string& name) : model(name) {}
