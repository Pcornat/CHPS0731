//
// Created by Florent on 15/10/2018.
//

#include "mesh.h"
#include "triangle.h"

bool Mesh::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int complexite) {
	bool intersect = false;
	auto& listVertex(model.getListVertex());
	for (auto&& face : model.getListFaces()) {
		Triangle triangle;
		try {
			triangle = Triangle(nullptr, listVertex.at(face.s1) + this->center, listVertex.at(face.s2) + this->center,
								listVertex.at(face.s3) + this->center);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		if ((intersect = triangle.calculIntersection(rayon, scene, I, complexite))) {
			glm::vec3 s1s2(listVertex.at(face.s2) - listVertex.at(face.s1));
			glm::vec3 s1s3(listVertex.at(face.s3) - listVertex.at(face.s1));
			I.at(I.size() - 1).setNormal(glm::cross(s1s2, s1s3));
		}
	}
	return intersect;
}

Mesh::Mesh(Material* material, const std::string& name, unsigned int factor) : Objet(material), model(name), factor(factor) {
	glm::vec3 min(std::numeric_limits<float>::lowest()), max;
	auto& listVertex(model.getListVertex());
	/* TODO : min max sur les x, y et z pour la boîte */
	for (auto&& face : model.getListFaces()) {

	}
}

Mesh::Mesh(Material* material, std::string&& name, unsigned int factor) : Objet(material), model(name), factor(factor) {}

Mesh& Mesh::operator=(Mesh&& mesh) noexcept {
	if (this != &mesh) {
		this->model = std::move(mesh.model);
	}
	return *this;
}
