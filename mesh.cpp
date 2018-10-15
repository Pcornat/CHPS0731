//
// Created by Florent on 15/10/2018.
//

#include "mesh.h"

bool Mesh::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int complexite) {

	return false;
}

Mesh::Mesh(const std::string& name) : model(name) {}

Mesh::Mesh(std::string&& name) : model(name) {}

Mesh& Mesh::operator=(Mesh&& mesh) noexcept {
	if (this != &mesh) {
		this->model = std::move(mesh.model);
	}
	return *this;
}
